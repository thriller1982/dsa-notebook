#ifndef _FATAL_H_
#define _FATAL_H_
#include <stdio.h>
#include <stdlib.h>
#define Error(Str)        FatalError(Str)
#define FatalError(Str)   fprintf(stderr, "%s\n", Str), exit(1)

#endif