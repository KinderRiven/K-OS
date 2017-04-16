#ifndef INCLUDE_STRING_H_
#define INCLUDE_STRING_H_

#include "types.h"

int strcmp(const char *str1, const char *str2);

int strlen(const char *str);

void bzero(void *dest, uint32_t len);

void memset(void *dest, uint8_t val, uint32_t len);

#endif
