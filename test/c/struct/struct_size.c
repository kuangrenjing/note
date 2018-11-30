/*
 *     aligned
 *   packed 
 */

struct SGost{
	char a;
	char b;
	char c;
	uint8_t d;
	uint32_t e;
	uint64_t f;
};

//用packed修饰后,变为1字节对齐,这个常用于与协议有关的网络传输中