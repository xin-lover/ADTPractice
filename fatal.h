#ifndef __FATAL_HEADER_
#define __FATAL_HEADER_

#include <stdio.h>
#include <stdlib.h>

void FatalError(char *msg)
{
		printf("%s\n",msg);
		exit(1);
}

void Error(char *msg)
{
		printf("%s\n",msg);
}

#endif


