#define BOOL	bool
#define BYTE	unsigned char
#define WORD	unsigned short
#define LPCSTR	const unsigned char*
#define LPBYTE	unsigned char*

#define TRUE	1
#define FALSE	0

#define lstrlen(a) strlen((const char *)a)
#define min(a,b)	(a < b ? a : b)
#define ZeroMemory(a,b)	{ \
	int zmi;\
	for(zmi = 0; zmi < (int)b; ++zmi) { \
		*((char *)a + zmi) = 0; \
	} \
}

//#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
