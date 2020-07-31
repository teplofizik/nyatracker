// ***********************************************************
//	argparser.h
// 	Парсер аргументов
//
//  teplofizik, 2017
// ***********************************************************

#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifndef _ARGPARSER_H
#define _ARGPARSER_H

	void ap_Init(int argc, char * argv[]);
	const char * ap_GetValue(const char * Name, const char * Default);
	bool ap_HasArg(const char *Name);
	void ap_Free(void);

#endif
