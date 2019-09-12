#include <stdio.h>
char pstrWeather[64];

char* weather()
{
	snprintf(pstrWeather, 64, "today is not fine!");
	return pstrWeather;
}