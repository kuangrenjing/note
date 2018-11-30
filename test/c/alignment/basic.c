#include <stdio.h>
#include <stdint.h>

void char_alignment(void)
{
	char a;
	char b;
	char c;
	uint16_t d;
	char e;
	uint32_t f;

	char g;
	int h = 0;
	//for(h = 0; h < 10; ++h)
	{
		char i;
		char j;
		printf("i's addr is %p\n", &i);
		printf("j's addr is %p\n", &j);
		a += b;
	}

	char k;

	printf("a's addr is %p\n", &a);
	printf("b's addr is %p\n", &b);
	printf("c's addr is %p\n", &c);
	printf("d's addr is %p\n", &d);
	printf("e's addr is %p\n", &e);
	printf("f's addr is %p\n", &f);
	printf("g's addr is %p\n", &g);
	printf("h's addr is %p\n", &h);
	printf("k's addr is %p\n", &k);

	unsigned aaa = 10;
	unsigned bbb = 8;

	unsigned ccc = bbb - aaa;
	printf("ccc is %u\n", ccc);
	printf("ccc is %d\n", ccc);

	char *pstrTemp;

	size_t iLenT = snprintf(pstrTemp, 0, "mqs love who?");
	printf("iLenT is %d\n", iLenT);
}