https://www.cnblogs.com/lifan3a/articles/5556157.html
http://blog.sina.com.cn/s/blog_44c488680100uan5.html
http://blog.sina.com.cn/s/blog_44c488680100uan5.html

https://blog.csdn.net/DroidPhone/article/details/6271122  ALSA架构简介
https://blog.csdn.net/droidphone/article/details/6289712  声卡的创建
https://blog.csdn.net/droidphone/article/details/6308006  PCM设备的创建
https://blog.csdn.net/droidphone/article/details/6409983  Control设备的创建
https://blog.csdn.net/droidphone/article/details/7165482  移动设备中的ALSA（ASoC）
https://blog.csdn.net/droidphone/article/details/7231605  ASoC架构中的Machine   这一篇其实是ALSA代码的入口
https://blog.csdn.net/droidphone/article/details/7283833  ASoC架构中的Codec
https://blog.csdn.net/droidphone/article/details/7316061  ASoC架构中的Platform



alsa注册的声卡在/dev/snd下

arecord是linux的播放音乐命令：
arecord -l 列出声卡

snd_card_create alsa-lib


alsa machine驱动把设备设置为linux的platform设备。

0、引入
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
DAI:Digital Audio Interfaces(音频设备的硬件接口)
	PCM接口
	I2S接口
		NAU85L40具有，但我们不用
	AC97接口
	TDM接口(mcbsp接口可直接对接)
		NAU85L40具有，且是我们使用


1、简介：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	ALSA是Advanced Linux Sound Architecture(高级Linux声音架构)的缩写。在内核设备驱
动层，ALSA提供了alsa-driver，同时在应用层，ALSA为我们提供了alsa-lib，应用程序只要调用
alsa-lib提供的API，即可以完成对底层音频硬件的控制。

	物理的编解码器(Codec)与处理器之间通过I2C、SPI总线和数字音频接口(DAI)进行通信。I2C、
SPI读写编解码器的控制寄存器，数字音频接口传输PCM等格式的音频数据。

2、asoc
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	ALSA System on Chip。alsa-soc其实是对alsa-driver的进一步封装，他针对嵌入式设备提
供了一些列增强的功能。alsa-lib对PC和嵌入式设备是统一的。

3、asoc的硬件架构
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	通常，就像软件领域里的抽象和重用一样，嵌入式设备的音频系统可以被划分为板载硬件(
Machine)、Soc(Platform)、Codec三大部分。

	Machine是指某一款机器，可以是某款设备，某款开发板，又或者是某款智能手机，由此可以看
出Machine几乎是不可重用的，每个Machine上的硬件实现可能都不一样，CPU不一样，Codec不一样，
音频的输入、输出设备也不一样，Machine为CPU、Codec、输入输出设备提供了一个载体。

	Platform一般是指某一个SoC平台，比如pxaxxx,s3cxxxx,omapxxx等等，与音频相关的通常包
含该SoC中的时钟、DMA、I2S、PCM等等，只要指定了SoC，那么我们可以认为它会有一个对应的
Platform，它只与SoC相关，与Machine无关，这样我们就可以把Platform抽象出来，使得同一款SoC
不用做任何的改动，就可以用在不同的Machine中。实际上，把Platform认为是某个SoC更好理解。

	Codec字面上的意思就是编解码器，Codec里面包含了I2S接口、D/A、A/D、Mixer、PA（功放），
通常包含多种输入（Mic、Line-in、I2S、PCM）和多个输出（耳机、喇叭、听筒，Line-out），Codec
和Platform一样，是可重用的部件，同一个Codec可以被不同的Machine使用。嵌入式Codec通常通过
I2C对内部的寄存器进行控制。

4、asoc软件架构
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	在软件层面，ASoC也把嵌入式设备的音频系统同样分为3大部分：Machine，Platform和Codec。

	Codec驱动：ASoC中的一个重要设计原则就是要求Codec驱动是平台无关的，它包含了一些音频
的控件（Controls），音频接口，DAMP（动态音频电源管理）的定义和某些Codec IO功能。为了保证
硬件无关性，任何特定于平台和机器的代码都要移到Platform和Machine驱动中。所有的Codec驱动都
要提供以下特性：
		Codec DAI 和 PCM的配置信息（数字音频接口部分）；
		Codec的IO控制方式（I2C，SPI等）；
		Mixer和其他的音频控件；
		Codec的ALSA音频操作接口；

	必要时，也可以提供以下功能：
		DAPM描述信息；
		DAPM事件处理程序；
		DAC数字静音控制

	Platform驱动：它包含了该SoC平台的音频DMA和音频接口的配置和控制(I2S，PCM，AC97等
等),它也不能包含任何与板子或机器相关的代码。

	Machine驱动  Machine驱动负责处理机器特有的一些控件和音频事件（例如，当播放音频时，
需要先行打开一个放大器）；单独的Platform和Codec驱动是不能工作的，它必须由Machine驱动把
它们结合在一起才能完成整个设备的音频处理工作。

5、asoc数据结构
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	asoc提供了一系列数据结构：snd_codec_device和snd_soc_card代表着Machine驱动，
snd_soc_platform则代表着Platform驱动，snd_soc_codec和soc_codec_device则代表了Codec
驱动，而snd_soc_dai_link则负责连接Platform和Codec。

6、machine、platform、codec驱动在DM3730的OMAP3EVM开发板SDK中的实现：
DAI驱动：
	../sound/soc/omap/omap-mcbsp.c "OMAP ALSA SoC DAI driver using McBSP port"
Machine驱动：
	../sound/soc/omap/omap3evm.c "ALSA SoC support for OMAP3 EVM"  platform device
	../sound/soc/soc-core.c                                        platform driver
platform驱动：
	./sdk/arch/arm/mach-omap2/devices.c                                  platform device
	../sound/soc/omap/omap-pcm.c "ALSA PCM interface for the OMAP SoC"   platform driver
codec驱动当然要自己实现：
	../sound/soc/codec/**

7、machine、platform、codec驱动的功能分析
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	machine的platform device模块定义了一个snd_soc_card、一个platform_device*类型的
全局静态变量，在模块入口函数中给platform_device*类型变量分配空间，并把snd_soc_card类
型变量赋值给它的drvdata成员。

	snd_soc_card类型变量有两个重要成员：name、dai_link。name用于匹配machine的platform
driver模块；dai_link是snd_soc_dai_link类型变量数组，指定了Platform、Codec、codec_dai、
cpu_dai的名字，稍后Machine驱动将会利用这些名字去匹配已经在系统中注册的platform，codec，
dai(都是linux platform驱动)，dai_link还有一个重要成员叫ops，它是snd_soc_ops类型的。

	platform device模块要先于platform driver模块加载。

	machine的platform driver模块定义了一个platform_driver类型的全局静态变量。

	platform_driver类型有三个重要成员driver、probe、remove。driver又有一个成员叫name，
用于与platform device的name进行匹配，匹配成功会触发probe函数调用。

	以machine的platform driver的probe函数为入口，完成了一系列的soc初始化工作，所以这个
函数是非常重要的。

	probe函数取出匹配中的platform device的platform_device*类型变量，其drvdata成员是
snd_soc_card类型全局变量。调用snd_soc_register_card注册这个音频卡。然后调用
snd_soc_instantiate_card来执行codec、platform、dai的绑定工作。

	soc_probe(probe)->snd_soc_register_card->snd_soc_instantiate_cards->                                                                                              

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	ASoC定义了三个全局的链表头变量：codec_list、dai_list、platform_list，系统中所有的
Codec、DAI、Platform都在注册时连接到这三个全局链表上。


i2c_add_driver

