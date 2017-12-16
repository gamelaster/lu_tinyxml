#include "SQMain.h"
#include "SQFuncs.h"
#include <stdio.h>

SQAPI sq;

/*
 * SQLoad() is called when the script requests loading this module. This is where module
 * initialization and native function/constant registering is done.
 */
LU_EXPORT SQRESULT SQLoad( HSQUIRRELVM v, SQAPI api )
{
	sq = api;

	RegisterFuncs( v );

	printf("\n[tinyxml] XML Module 1.0 by GAMELASTER loaded.\n");

	return SQ_OK;
}

/*
 * SQUnload() gets called when a script calls UnloadModule() or the script using this module
 * is being unloaded. Usually nothing is required to do here, if the module allocates memory
 * for its own usage this memory should be freed.
 */
LU_EXPORT SQRESULT SQUnload( void )
{
	return SQ_OK;
}

/*
 * SQCallback is reserved for possible future callbacks.
 * For a list of callbacks, check enum eSquirrelCallback in SQModule.h
 */
LU_EXPORT SQRESULT SQCallback( unsigned int uiCallback, void* pData )
{
	return SQ_OK;
}

/*
 * SQPulse() is a function which gets called on every server cycle.
 */
LU_EXPORT SQRESULT SQPulse( void )
{
	return SQ_OK;
}
