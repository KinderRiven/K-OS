#include "string.h"


int strlen(const char *str){
	
	int length = 0;
	
	while(str[length] != '\0')
	{
		length++;
	}	
	
	return length;
}

int strcmp(const char *str1, const char *str2)
{

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int i = 0;

	for(i = 0; i <= len1 && i <= len2; i++)
	{
		if(str1[i] > str2[i])
			return 1;
		if(str1[i] < str2[i])
			return -1;
	}
	
	return 0;
}

void memset(void *dest, uint8_t val, uint32_t len)
{
	uint8_t *dst = (uint8_t *)dest;
	
	for(; len != 0; len--){
		*dst ++ = val;
	}
}

void bzero(void *dest, uint32_t len)
{
	memset(dest, 0, len);
}
