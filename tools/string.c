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
