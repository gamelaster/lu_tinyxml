#include "SQHelper.h"

extern SQAPI sq;

void SquirrelAddClassBegin(HSQUIRRELVM v, const SQChar* class_name)
{
	sq->pushroottable(v);
	sq->pushstring(v, _SC(class_name), -1);
	sq->newclass(v, SQFalse);
}

void SquirrelAddClassMethod(HSQUIRRELVM v, const SQChar* function_name, SQFUNCTION function, SQBool is_static, unsigned char params_count, const SQChar* params_mask)
{
	sq->pushstring(v, _SC(function_name), -1);
	sq->newclosure(v, function, 0);
	if (params_count > 0)
	{
		params_count++;
		char new_params[32];
		sprintf(new_params, "x%s", params_mask);
		sq->setparamscheck(v, params_count, _SC(new_params));
	}
	sq->setnativeclosurename(v, -1, _SC(function_name));
	sq->newslot(v, -3, is_static); 
}

void SquirrelAddClassEnd(HSQUIRRELVM v)
{
	sq->newslot(v, -3, SQFalse);
	sq->pop(v, 1);
}

void SquirrelCreateClassInstance(HSQUIRRELVM v, const SQChar* class_name, SQUserPointer instance, SQRELEASEHOOK release_hook)
{
	sq->pushroottable(v);
	sq->pushstring(v, _SC(class_name), -1);
	sq->get(v, -2);
	sq->createinstance(v, -1);
	if (instance != nullptr)
	{
		sq->setinstanceup(v, -1, instance);
	}
	sq->remove(v, -2);
	if (release_hook != NULL)
	{
		sq->setreleasehook(v, -1, release_hook);
	}
	sq->remove(v, -2);
}