//
// Squirrel helper functions
// by Marek gamelaster Kraus
//
#pragma once
#ifndef _SQHELPER_H
#define _SQHELPER_H

#include "SQMain.h"
#include "squirrel.h"
#include <stdio.h>

#define _SQUIRRELDEF( x ) SQInteger x( HSQUIRRELVM v )

#ifdef __cplusplus
extern "C" {
#endif

	void SquirrelAddClassBegin(HSQUIRRELVM v, const SQChar * class_name);
	void SquirrelAddClassMethod(HSQUIRRELVM v, const SQChar* function_name, SQFUNCTION function, SQBool is_static = SQFalse, unsigned char params_count = 0, const SQChar* params_mask = NULL);
	void SquirrelAddClassEnd(HSQUIRRELVM v);
	void SquirrelCreateClassInstance(HSQUIRRELVM v, const SQChar* class_name, SQUserPointer instance = nullptr, SQRELEASEHOOK release_hook = NULL);
#ifdef __cplusplus
}
#endif

#endif

