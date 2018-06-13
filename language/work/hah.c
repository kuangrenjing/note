/*

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
DAI驱动(.name = "omap-mcbsp-dai")：
	sdk/arch/arm/plat-omap/include/plat/mcbsp.h   OMAP_MCBSP_PLATFORM_DEVICE
	sdk/arch/arm/mach-omap2/devices.c             platform device 静态加载
	../sound/soc/omap/omap-mcbsp.c                platform driver 动态加载 snd_soc_register_dai

Machine驱动(.name = "soc-audio")：
	../sound/soc/omap/omap3evm.c   platform device 动态加载
	../sound/soc/soc-core.c        platform driver 动态加载

platform驱动(.name = "omap-pcm-audio")：
	sdk/arch/arm/mach-omap2/devices.c        platform device 静态加载
	../sound/soc/omap/omap-pcm.c             platform driver 动态加载  snd_soc_register_platform
codec驱动当然要自己实现：
	../sound/soc/codec/nau8540.c             通过I2C驱动加载

7、machine、platform、codec驱动的功能分析
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	machine的platform device模块定义了一个snd_soc_card、一个platform_device*类型的
全局静态变量，在模块入口函数中给platform_device*类型变量分配空间，并把snd_soc_card类
型变量赋值给它的drvdata成员。

	snd_soc_card类型变量有两个重要成员：name、dai_link。name用于匹配machine的platform
driver模块；dai_link是snd_soc_dai_link类型变量数组，指定了Platform、Codec、codec_dai、
cpu_dai的名字，稍后Machine驱动将会利用这些名字去匹配已经在系统中注册的platform，codec，
dai(都是linux platform驱动)，dai_link还有一个重要成员叫ops，它是snd_soc_ops类型的。
	snd_soc_card类型有“struct snd_soc_pcm_runtime *rtd”成员。

	platform device模块要先于platform driver模块加载。

	machine的platform driver模块定义了一个platform_driver类型的全局静态变量。

	platform_driver类型有三个重要成员driver、probe、remove。driver又有一个成员叫name，
用于与platform device的name进行匹配，匹配成功会触发probe函数调用。

	以machine的platform driver的probe函数为入口，完成了一系列的soc初始化工作，所以这个
函数是非常重要的。

	probe函数取出匹配中的platform device的platform_device*类型变量，其drvdata成员是
snd_soc_card类型全局变量。调用snd_soc_register_card注册这个音频卡。然后调用
snd_soc_instantiate_card来执行codec、platform、dai的绑定工作。

	soc_probe(probe)->snd_soc_register_card->snd_soc_instantiate_cards->snd_soc_instantiate_card->soc_bind_dai_link

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	ASoC定义了三个全局的链表头变量：codec_list、dai_list、platform_list，系统中所有的
Codec、DAI、Platform都在注册时连接到这三个全局链表上。

	sound/soc/omap/omap-mcbsp.c中有以下定义：
	line689:static struct snd_soc_dai_driver omap_mcbsp_dai

	line848:static struct platform_driver asoc_mcbsp_driver = {
		.driver = {
				.name = "omap-mcbsp-dai",
				.owner = THIS_MODULE,
		},

		.probe = asoc_mcbsp_probe,
		.remove = __devexit_p(asoc_mcbsp_remove),
	};

	sdk/arch/arm/plat-omap/include/plat/mcbsp.h中有以下定义：
	//macro for building platform_device for McBSP ports
	#define OMAP_MCBSP_PLATFORM_DEVICE(port_nr)             \
	static struct platform_device omap_mcbsp##port_nr = {   \
		.name   = "omap-mcbsp-dai",                     \
		.id     = OMAP_MCBSP##port_nr,                  \
	}

	sdk/arch/arm/mach-omap2/devices.c中
	platform_device_register(&omap_mcbsp1)<-static void omap_init_audio(void)<-static int __init omap2_init_devices(void)<-arch_initcall(omap2_init_devices)
	platform_device_register(&omap_pcm)   <-
	linux内核启动过程中会自动调用arch_initcall。


在soc-core.c中定义了下列函数：
snd_soc_register_platform
snd_soc_register_codec
snd_soc_register_dai


i2c_add_driver

8、声音的一些基本概念：
样本长度(sample)：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	样本是记录音频数据最基本的单位，常见的有8位和16位。反映采样精度

通道数(channel)：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	该参数为1表示单声道，2则是立体声。

桢(frame)：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	桢记录了一个声音单元，其长度为样本长度与通道数的乘积。

采样率(rate)：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	每秒钟采样次数，该次数是针对桢而言。

周期(period)：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	音频设备一次处理所需要的桢数，对于音频设备的数据访问以及音频数据的存储，都是以此为单位。
通过声卡的中断来体现，但我们现在只有codec，所有用mcbsp接口的中断？

	DM37x文档第21章p3061-p3221

	arch/arm/plat-omap/include/mach/mcbsp.h
	omap-mcbsp-dai这个是cpu_dai

交错模式(interleaved)：
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	是一种音频数据的记录方式，在交错模式下，数据以连续桢的形式存放，即首先记录完桢1的左
声道样本和右声道样本（假设为立体声格式），再开始桢2的记录。而在非交错模式下，首先记录的
是一个周期内所有桢的左声道样本，再记录右声道样本，数据是以连续通道的方式存储。不过多数情
况下，我们只需要使用交错模式就可以了。

8、alsa-lib编程：
https://code.woboq.org/linux/linux/sound/soc/codecs/nau8540.h.html
https://code.woboq.org/linux/linux/sound/soc/codecs/nau8540.c.html

snd_pcm_open


9、几个典型的调用流程
设置hw_param参数时，调用流程：
snd_pcm_hw_params _snd_pcm_hw_params pcm->ops->hw_params----snd_pcm_hw_hw_params SNDRV_PCM_IOCTL_HW_PARAMS snd_pcm_common_ioctl1 snd_pcm_hw_params_user snd_pcm_hw_params substream->ops->hw_params soc_pcm_hw_params codec_dai->driver->ops->hw_params cpu_dai->driver->ops->hw_params cs4270_hw_params 
                                                                                                                                 在pcm_native.c文件中
设置mixer 参数时，volume为例，调用流程 snd_mixer_selem_set_playback_volume_all snd_mixer_selem_set_playback_volume set_volume_ops _snd_mixer_selem_set_volume---selem_write selem_write_main elem_write_volume snd_hctl_elem_write snd_ctl_elem_write snd_ctl_hw_elem_write snd_ctl_elem_write_user snd_ctl_elem_write snd_soc_put_volsw snd_soc_update_bits_locked regmap_update_bits_check IIS clk 设置流程 snd_pcm_common_ioctl1 snd_pcm_hw_params_user snd_pcm_hw_params substream->ops->hw_params soc_pcm_hw_params rtd->dai_link->ops->hw_params smdk_wm8994_pcm_hw_params snd_soc_dai_set_sysclk dai->driver->ops->set_sysclk i2s_set_sysclk 


10、alsa对声卡的描述
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	一个soc网卡可以有多个pcm逻辑设备(一般就是codec，即编解码器)，每个pcm设备有可以两个
个stream(playback stream和capture stream)，每个stream又可以有多个substream。

	在我司DM3730项目中，网卡有两个PCM设备，一个是AK4430用于播放、一个是Nau85l40，用于
声音采集，所以这两个pcm设备各有一个stream，AK4430的是playback stream，nau85l40的是
capture stream。

	前面说到soc是对alsa再封装，我们来看看alsa和soc分别是怎么描述网卡、PCM、stream和
substream的。

	include/sound/core.h定义alsa的结构
	include/sound/soc.h定义soc的结构

	声卡：
		alsa:include/sound/core.h:struct snd_card
		soc:include/sound/soc.h:struct snd_soc_card

	pcm
		alsa:include/sound/pcm.h:struct snd_pcm
		soc:include/sound/soc.h:struct snd_soc_pcm_runtime

	stream
		alsa:include/sound/pcm.h:struct snd_pcm_substream
		soc:include/sound/soc.h:struct snd_soc_pcm_stream

	substream
		alsa:include/sound/pcm.h:struct snd_pcm_substream

	前面说到，一个soc网卡可以有多个pcm，每个pcm可以有两个stream，每个stream可以有多个
substream，那这些个数在驱动中是怎么决定的呢？下面分别来看。

	pcm的数目由“struct snd_soc_card”类型的数组成员dai_link决定的，dai_link数组有多
少个成员，就有多少个pcm设备。这个数组是在machine platform device模块文件内定义的。

	substream的数目是由pcm对应的codec_dai的“struct snd_soc_dai_driver”类型的
“struct snd_soc_pcm_stream”类型成员决定。这个变量是在dai platform driver模块文件中
定义的。在我们的项目中就是sound/soc/omap/omap-mcbsp.c文件中的omap_mcbsp_dai变量。
“struct snd_soc_pcm_stream”类型可以分别定义play_back substream和capture substream
的数目。但在sound/soc/soc-core.c中soc_new_pcm函数中我们可以看到只要定义了substream
数目的下限，那substream的数目就是1。在我们的项目中substream的数目就是1。

	substream的重要性：配置和数据流都是以substream为原子的。

	一个pcm有4个重要组件：cpu_dai、codec_dai、codec、platform。

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
利用linux模块收集soc驱动：
	在sound/soc/soc-core.c中定义了四个全局静态链表：card_list、dai_list、platform_list、
codec_list。machine、codec_dai、platform、codec驱动都实作为linux的platform驱动模块，
利用linux的platform驱动和设备匹配机制，当匹配成功后的入口函数会分别调用snd_soc_register_card、
snd_soc_register_dai、snd_soc_register_platform、snd_soc_register_codec函数。这些函数
都带有相应的soc驱动参数，如struct snd_soc_dai_driver、struct snd_soc_platform_driver、
struct snd_soc_codec_driver，这样就把这些soc驱动加入到了相应全局链表中。


aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
把全局链表中的soc驱动分配到“struct snd_soc_card”的“struct snd_soc_pcm_runtime”成员中去：
	因为4个全局链表有新成员加入，那理论上card->rtd[].cpu_dai、codec_dai、platform、codec
还没有赋值的就有匹配中的可能，所以snd_soc_register_dai等四个函数还会调用
snd_soc_instantiate_cards->snd_soc_instantiate_card->soc_bind_dai_link函数来在四
个全局链表给card->rtd[].cpu_dai、codec_dai、platform、codec找驱动，
snd_soc_instantiate_card会被register系列函数反复调用，只有当所有card->rtd的四个驱动
都找到了，它才会执行soc_bind_dai_link函数后面的代码。


aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
snd_soc_instantiate_card调用snd_card_create

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
snd_soc_instantiate_card调用soc_probe_dai_link

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	soc_probe_dai_link调用soc_new_pcm->snd_pcm_new

int snd_pcm_new(struct snd_card *card, const char *id, int device,
		int playback_count, int capture_count,
		struct snd_pcm **rpcm);

	soc_new_pcm

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
snd_soc_instantiate_card调用snd_card_register：
注册声卡：
	在这个阶段会遍历声卡下的所有逻辑设备，并且调用各设备的注册回调函数，对于pcm，就是
snd_pcm_dev_register函数，该回调函数建立了和用户空间应用程序（alsa-lib）通信所用的设
备文件节点:/dev/snd/pcmCxxDxxp和/dev/snd/pcmCxxDxxc

snd_pcm_dev_register

aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
int snd_pcm_new_stream(struct snd_pcm *pcm, int stream, int substream_count);
http://www.alivepea.me/kernel/alsa-pcm/
http://www.cnblogs.com/fellow1988/p/6204183.html


11、alsa-lib硬件配置
sound\core\pcm_native.c的snd_pcm_hw_params_user函数

*/

/* SoC card */
/*
在machine platform device模块文件中定义
*/
struct snd_soc_card {
	const char *name;               //1-3-1、定义时直接给出
	struct device *dev;             //2-1-1、platform_device_add函数生成，soc_probe函数赋值
	struct snd_card *snd_card;
	struct module *owner;          //应该在定义时给出，但没有

	struct list_head list;
	struct mutex mutex;

	bool instantiated;

	int (*probe)(struct platform_device *pdev);
	int (*remove)(struct platform_device *pdev);

	/* the pre and post PM functions are used to do any PM work before and
	 * after the codec and DAI's do any PM work. */
	int (*suspend_pre)(struct platform_device *pdev, pm_message_t state);
	int (*suspend_post)(struct platform_device *pdev, pm_message_t state);
	int (*resume_pre)(struct platform_device *pdev);
	int (*resume_post)(struct platform_device *pdev);

	/* callbacks */
	int (*set_bias_level)(struct snd_soc_card *,
			      enum snd_soc_bias_level level);

	long pmdown_time;

	/* CPU <--> Codec DAI links  */
	struct snd_soc_dai_link *dai_link;  //1-3-2、定义时直接给出
	int num_links;                      //1-3-3、定义时直接给出
	struct snd_soc_pcm_runtime *rtd;    //3-2-1、soc_probe->snd_soc_register_card函数用dai_link初始化
	int num_rtd;                        //3-2-2、就等于num_links

	struct work_struct deferred_resume_work;

	/* lists of probed devices belonging to this card */
	struct list_head codec_dev_list;
	struct list_head platform_dev_list;
	struct list_head dai_dev_list;
};

/* main structure for soundcard */
/*
snd_soc_instantiate_card调用soc_bind_dai_link绑定完所有soc驱动后调用
snd_card_create函数创建，放在soc_card的snd_card成员中。
*/
struct snd_card {
	int number;			/* number of soundcard (index to
								snd_cards) */

	char id[16];			/* id string of this card */
	char driver[16];		/* driver name */
	char shortname[32];		/* short name of this soundcard */
	char longname[80];		/* name of this soundcard */
	char mixername[80];		/* mixer name */
	char components[128];		/* card components delimited with
								space */
	struct module *module;		/* top-level module */

	void *private_data;		/* private data for soundcard */
	void (*private_free) (struct snd_card *card); /* callback for freeing of
								private data */
	struct list_head devices;	/* devices */

	unsigned int last_numid;	/* last used numeric ID */
	struct rw_semaphore controls_rwsem;	/* controls list lock */
	rwlock_t ctl_files_rwlock;	/* ctl_files list lock */
	int controls_count;		/* count of all controls */
	int user_ctl_count;		/* count of all user controls */
	struct list_head controls;	/* all controls for this card */
	struct list_head ctl_files;	/* active control files */

	struct snd_info_entry *proc_root;	/* root for soundcard specific files */
	struct snd_info_entry *proc_id;	/* the card id */
	struct proc_dir_entry *proc_root_link;	/* number link to real id */

	struct list_head files_list;	/* all files associated to this card */
	struct snd_shutdown_f_ops *s_f_ops; /* file operations in the shutdown
								state */
	spinlock_t files_lock;		/* lock the files for this card */
	int shutdown;			/* this card is going down */
	int free_on_last_close;		/* free in context of file_release */
	wait_queue_head_t shutdown_sleep;
	struct device *dev;		/* device assigned to this card */
	struct device *card_dev;	/* cardX object for sysfs */

#ifdef CONFIG_PM
	unsigned int power_state;	/* power state */
	struct mutex power_lock;	/* power lock */
	wait_queue_head_t power_sleep;
#endif

#if defined(CONFIG_SND_MIXER_OSS) || defined(CONFIG_SND_MIXER_OSS_MODULE)
	struct snd_mixer_oss *mixer_oss;
	int mixer_oss_change_count;
#endif
};


