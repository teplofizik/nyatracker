// ***********************************************************
//	argparser.c
// 	Парсер аргументов
//
//  teplofizik, 2017
// ***********************************************************

#include "argparser.h"
#include <string.h>
#include <stdio.h>

static int     prog_argc;
static char ** prog_argv;

static const char * GetArgValue(const char *Name)
{
	int i;
	for (i = 0; i < prog_argc; i++)
	{
		char ArgN[50];
		char * c;
		
		sprintf(ArgN, "%s=", Name);
		c = strstr(prog_argv[i], ArgN);
		if (c == prog_argv[i])
			return prog_argv[i] + strlen(ArgN);
	}
	
	return 0;
}

bool ap_HasArg(const char * Name)
{
	int i;
	for (i = 0; i < prog_argc; i++)
	{
		if (strstr(prog_argv[i], Name) == prog_argv[i])
			return true;
	}
	
	return false;
}

void ap_Init(int argc, char * argv[])
{
	prog_argc = argc;
	prog_argv = argv;
}

const char * ap_GetValue(const char * Name, const char * Default)
{
	const char * Value = GetArgValue(Name);
	return (Value) ? Value : Default;
}

void ap_Free(void)
{
	
}