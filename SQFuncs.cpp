#include "SQFuncs.h"
#include <stdio.h>
#include "vendor\tinyxml2\tinyxml2.h"
using namespace tinyxml2;
extern SQAPI sq;
#include "SQXMLClass.h"
#include "SQXMLNodeClass.h"
#include "SQXMLElementClass.h"


/*_SQUIRRELDEF( HelloSquirrel )
{
	sq->pushstring( v, _SC( "Hello Squirrel Module!" ), -1 );

	return 1; // return 0 indicates the Squirrel function does not return a value, 1 returns a value
}

_SQUIRRELDEF( Sum )
{
	SQInteger iArgCount = sq->gettop( v ); // Get the argument count

	if ( iArgCount == 3 ) // Argument count = 2 arguments + root table = 3 
	{
		SQInteger i1 = 0, i2 = 0;

		sq->getinteger( v, 2, &i1 ); // Get argument 1 in slot 2 to 'i1'
		sq->getinteger( v, 3, &i2 ); // Get argument 2 in slot 3 to 'i2'

		sq->pushinteger( v, i1 + i2 ); // Return the sum of these two numbers
		return 1;
	}

	sq->pushbool( v, SQFalse );
	return 1;
}*/


//XMLNode*


/*SQInteger RegisterSquirrelFunc( HSQUIRRELVM v, SQFUNCTION f, const SQChar* fname, unsigned char ucParams, const SQChar* szParams )
{
	char szNewParams[ 32 ];

	sq->pushroottable( v );
	sq->pushstring( v, fname, -1 );
	sq->newclosure( v, f, 0 ); // create a new function

	if ( ucParams > 0 ) 
	{
		ucParams++; //This is to compensate for the root table
		
		sprintf( szNewParams, "t%s", szParams );

		sq->setparamscheck( v, ucParams, szNewParams ); // Add a param type check
	}

	sq->setnativeclosurename( v, -1, fname );
	sq->newslot( v, -3, SQFalse );
	sq->pop( v, 1 ); // pops the root table

	return 0;
}*/


void RegisterFuncs( HSQUIRRELVM v )
{
	SquirrelAddClassBegin(v, "XML");
	SquirrelAddClassMethod(v, "constructor", XML_Constructor);
	SquirrelAddClassMethod(v, "LoadFile", XML_LoadFile, SQFalse, 1, "s");
	SquirrelAddClassMethod(v, "SaveFile", XML_SaveFile, SQFalse, 1, "s");
	SquirrelAddClassMethod(v, "Parse", XML_Parse, SQFalse, 1, "s");
	SquirrelAddClassMethod(v, "ErrorID", XML_ErrorID);
	SquirrelAddClassMethod(v, "ErrorName", XML_ErrorName);
	SquirrelAddClassMethod(v, "ErrorLineNumber", XML_ErrorLineNumber);
	SquirrelAddClassMethod(v, "ErrorString", XML_ErrorString);
	SquirrelAddClassMethod(v, "RootElement", XML_RootElement);
	SquirrelAddClassMethod(v, "NewElement", XML_NewElement, SQFalse, 1, "s");
	SquirrelAddClassMethod(v, "NewDeclaration", XML_NewDeclaration);
	SquirrelAddClassMethod(v, "DeleteNode", XML_DeleteNode, SQFalse, 1, "x");
	SquirrelAddClassMethod(v, "Test", XML_Test);
	//XMLNode functions in XMLDocument
	SquirrelAddClassMethod(v, "InsertFirstChild", XMLNode_InsertFirstChild, SQFalse, 1, "x");
	SquirrelAddClassMethod(v, "InsertEndChild", XMLNode_InsertEndChild, SQFalse, 1, "x");
	SquirrelAddClassMethod(v, "InsertAfterChild", XMLNode_InsertAfterChild, SQFalse, 2, "xx");
	SquirrelAddClassMethod(v, "Value", XMLNode_Value);
	SquirrelAddClassMethod(v, "SetValue", XMLNode_SetValue, SQFalse, 1, "s");
	SquirrelAddClassMethod(v, "GetLineNumber", XMLNode_GetLineNumber);
	SquirrelAddClassMethod(v, "Parent", XMLNode_Parent);
	SquirrelAddClassMethod(v, "NoChildren", XMLNode_NoChildren);
	SquirrelAddClassMethod(v, "FirstChild", XMLNode_FirstChild);
	SquirrelAddClassMethod(v, "FirstChildElement", XMLNode_FirstChildElement);
	SquirrelAddClassMethod(v, "LastChild", XMLNode_LastChild);
	SquirrelAddClassMethod(v, "LastChildElement", XMLNode_LastChildElement);
	SquirrelAddClassMethod(v, "PreviousSibling", XMLNode_PreviousSibling);
	SquirrelAddClassMethod(v, "PreviousSiblingElement", XMLNode_PreviousSiblingElement);
	SquirrelAddClassMethod(v, "NextSibling", XMLNode_NextSibling);
	SquirrelAddClassMethod(v, "NextSiblingElement", XMLNode_NextSiblingElement);
	SquirrelAddClassMethod(v, "DeleteChildren", XMLNode_DeleteChildren);
	SquirrelAddClassMethod(v, "DeleteChild", XMLNode_DeleteChild, SQFalse, 1, "x");

	SquirrelAddClassEnd(v);
	//XMLNode*
	SquirrelAddClassBegin(v, "XMLNode");
	SquirrelAddClassMethod(v, "InsertFirstChild", XMLNode_InsertFirstChild, SQFalse, 1, "x");
	SquirrelAddClassMethod(v, "InsertEndChild", XMLNode_InsertEndChild, SQFalse, 1, "x");
	SquirrelAddClassMethod(v, "InsertAfterChild", XMLNode_InsertAfterChild, SQFalse, 2, "xx");
	SquirrelAddClassMethod(v, "Value", XMLNode_Value);
	SquirrelAddClassMethod(v, "SetValue", XMLNode_SetValue, SQFalse, 1, "s");
	SquirrelAddClassMethod(v, "GetLineNumber", XMLNode_GetLineNumber);
	SquirrelAddClassMethod(v, "Parent", XMLNode_Parent);
	SquirrelAddClassMethod(v, "NoChildren", XMLNode_NoChildren);
	SquirrelAddClassMethod(v, "FirstChild", XMLNode_FirstChild);
	SquirrelAddClassMethod(v, "FirstChildElement", XMLNode_FirstChildElement);
	SquirrelAddClassMethod(v, "LastChild", XMLNode_LastChild);
	SquirrelAddClassMethod(v, "LastChildElement", XMLNode_LastChildElement);
	SquirrelAddClassMethod(v, "PreviousSibling", XMLNode_PreviousSibling);
	SquirrelAddClassMethod(v, "PreviousSiblingElement", XMLNode_PreviousSiblingElement);
	SquirrelAddClassMethod(v, "NextSibling", XMLNode_NextSibling);
	SquirrelAddClassMethod(v, "NextSiblingElement", XMLNode_NextSiblingElement);
	SquirrelAddClassMethod(v, "DeleteChildren", XMLNode_DeleteChildren);
	SquirrelAddClassMethod(v, "DeleteChild", XMLNode_DeleteChild, SQFalse, 1, "x");

	SquirrelAddClassEnd(v);
	//XMLElement*
	SquirrelAddClassBegin(v, "XMLElement");
	SquirrelAddClassMethod(v, "Attribute", XMLElement_Attribute, SQFalse, 1, "s");
	SquirrelAddClassMethod(v, "IntegerAttribute", XMLElement_IntegerAttribute, SQFalse, 1, "s");
	SquirrelAddClassMethod(v, "FloatAttribute", XMLElement_FloatAttribute, SQFalse, 1, "s");
	SquirrelAddClassMethod(v, "BoolAttribute", XMLElement_BoolAttribute, SQFalse, 1, "s");
	SquirrelAddClassMethod(v, "SetAttribute", XMLElement_SetAttribute);
	SquirrelAddClassMethod(v, "GetText", XMLElement_GetText);
	SquirrelAddClassMethod(v, "SetText", XMLElement_SetText, SQFalse, 1, "s");
	//XMLNode functions in XMLElement
	SquirrelAddClassMethod(v, "InsertFirstChild", XMLNode_InsertFirstChild, SQFalse, 1, "x");
	SquirrelAddClassMethod(v, "InsertEndChild", XMLNode_InsertEndChild, SQFalse, 1, "x");
	SquirrelAddClassMethod(v, "InsertAfterChild", XMLNode_InsertAfterChild, SQFalse, 2, "xx");
	SquirrelAddClassMethod(v, "Value", XMLNode_Value);
	SquirrelAddClassMethod(v, "SetValue", XMLNode_SetValue, SQFalse, 1, "s");
	SquirrelAddClassMethod(v, "GetLineNumber", XMLNode_GetLineNumber);
	SquirrelAddClassMethod(v, "Parent", XMLNode_Parent);
	SquirrelAddClassMethod(v, "NoChildren", XMLNode_NoChildren);
	SquirrelAddClassMethod(v, "FirstChild", XMLNode_FirstChild);
	SquirrelAddClassMethod(v, "FirstChildElement", XMLNode_FirstChildElement);
	SquirrelAddClassMethod(v, "LastChild", XMLNode_LastChild);
	SquirrelAddClassMethod(v, "LastChildElement", XMLNode_LastChildElement);
	SquirrelAddClassMethod(v, "PreviousSibling", XMLNode_PreviousSibling);
	SquirrelAddClassMethod(v, "PreviousSiblingElement", XMLNode_PreviousSiblingElement);
	SquirrelAddClassMethod(v, "NextSibling", XMLNode_NextSibling);
	SquirrelAddClassMethod(v, "NextSiblingElement", XMLNode_NextSiblingElement);
	SquirrelAddClassMethod(v, "DeleteChildren", XMLNode_DeleteChildren);
	SquirrelAddClassMethod(v, "DeleteChild", XMLNode_DeleteChild, SQFalse, 1, "x");


	SquirrelAddClassEnd(v);

}
