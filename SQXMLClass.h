#pragma once

SQInteger XML_ReleaseHook(SQUserPointer ptr, SQInteger size)
{
	XMLDocument* doc = (XMLDocument*)ptr;
	doc->~XMLDocument();
	delete doc;
	return 1;
}

_SQUIRRELDEF(XML_Constructor)
{
#ifdef _DEBUG
	printf("[XML] XML Constructor...\n");
#endif
	XMLDocument* doc = new XMLDocument();
	if (SQ_FAILED(sq->setinstanceup(v, 1, (SQUserPointer *)doc)))
	{
		return sq->throwerror(v, _SC("Error in 'XML.constructor': Couldn't setup instance of 'XML' class"));
	}
	sq->setreleasehook(v, 1, XML_ReleaseHook);
	sq->pushbool(v, SQTrue);
	return 1;
}

_SQUIRRELDEF(XML_LoadFile)
{
	SQUserPointer docPointer = NULL;
	const SQChar* filename = NULL;
	XMLDocument* doc = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &docPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.LoadFile': Called without instance"));
	}
	sq->getstring(v, 2, &filename);
	doc = (XMLDocument*)docPointer;

#ifdef _DEBUG
	printf("[XML] Loading file \"%s\"\n", filename);
#endif
	XMLError err = doc->LoadFile(filename);

	sq->pushinteger(v, err);
	return 1;
}

_SQUIRRELDEF(XML_SaveFile)
{
	SQUserPointer docPointer = NULL;
	const SQChar* filename = NULL;
	XMLDocument* doc = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &docPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.SaveFile': Called without instance"));
	}
	sq->getstring(v, 2, &filename);
	doc = (XMLDocument*)docPointer;

#ifdef _DEBUG
	printf("[XML] Saving file \"%s\"\n", filename);
#endif
	XMLError err = doc->SaveFile(filename);

	sq->pushinteger(v, err);
	return 1;

}

_SQUIRRELDEF(XML_Parse)
{
	SQUserPointer docPointer = NULL;
	const SQChar* xml = NULL;
	XMLDocument* doc = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &docPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.Parse': Called without instance"));
	}
	sq->getstring(v, 2, &xml);
	doc = (XMLDocument*)docPointer;

#ifdef _DEBUG
	printf("[XML] Parsing XML...\n");
#endif
	XMLError err = doc->Parse(xml);

	sq->pushinteger(v, err);
	return 1;
}

_SQUIRRELDEF(XML_ErrorID)
{
	SQUserPointer docPointer = NULL;
	XMLDocument* doc = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &docPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.ErrorID': Called without instance"));
	}
	doc = (XMLDocument*)docPointer;

	int errorId = doc->ErrorID();

#ifdef _DEBUG
	printf("[XML] Getting ErrorID: %i...\n", errorId);
#endif
	sq->pushinteger(v, errorId);
	return 1;
}

_SQUIRRELDEF(XML_ErrorName)
{
	SQUserPointer docPointer = NULL;
	XMLDocument* doc = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &docPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.ErrorName': Called without instance"));
	}
	doc = (XMLDocument*)docPointer;

	const char* errorName = doc->ErrorName();

	sq->pushstring(v, errorName, -1);
	return 1;
}

_SQUIRRELDEF(XML_ErrorLineNumber)
{
	SQUserPointer docPointer = NULL;
	XMLDocument* doc = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &docPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.ErrorLineNumber': Called without instance"));
	}
	doc = (XMLDocument*)docPointer;

	int errorLineNumber = doc->ErrorLineNum();

#ifdef _DEBUG
	printf("[XML] Getting ErrorLineNumber: %i...\n", errorLineNumber);
#endif
	sq->pushinteger(v, errorLineNumber);
	return 1;
}

_SQUIRRELDEF(XML_ErrorString)
{
	SQUserPointer docPointer = NULL;
	XMLDocument* doc = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &docPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.ErrorString': Called without instance"));;
	}
	doc = (XMLDocument*)docPointer;

	const char* errorString = doc->ErrorStr();

#ifdef _DEBUG
	printf("[XML] Getting ErrorString: %s...\n", errorString);
#endif
	sq->pushstring(v, errorString, -1);
	return 1;
}

_SQUIRRELDEF(XML_NewElement)
{
	SQUserPointer docPointer = NULL;
	const SQChar* elementName = NULL;
	XMLDocument* doc = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &docPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.NewElement': Called without instance"));
	}
	sq->getstring(v, 2, &elementName);
	doc = (XMLDocument*)docPointer;

#ifdef _DEBUG
	printf("[XML] Creating new element \"%s\"...\n", elementName);
#endif
	XMLElement* element = doc->NewElement(elementName);
	SquirrelCreateClassInstance(v, "XMLElement", element);
	return 1;
}

_SQUIRRELDEF(XML_NewDeclaration)
{
	SQUserPointer docPointer = NULL;
	const SQChar* declarationString = NULL;
	XMLDocument* doc = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &docPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.NewDeclaration': Called without instance"));
	}
	doc = (XMLDocument*)docPointer;

	XMLDeclaration* declaration = NULL;
#ifdef _DEBUG
	printf("[XML] Creating new declaration \"%s\"...\n", declarationString);
#endif
	if (sq->gettop(v) == 2 && sq->gettype(v, 2) == OT_STRING)
	{
		sq->getstring(v, 2, &declarationString);
		declaration = doc->NewDeclaration(declarationString);
	}
	else
	{
		declaration = doc->NewDeclaration();
	}

	SquirrelCreateClassInstance(v, "XMLNode", declaration);
	return 1;
}

_SQUIRRELDEF(XML_DeleteNode)
{
	SQUserPointer documentPointer = NULL;
	SQUserPointer nodePointer = NULL;
	XMLDocument* doc = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &documentPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.DeleteNode': Called without instance"));
	}
	sq->getinstanceup(v, 2, &nodePointer, NULL);
	doc = (XMLDocument*)documentPointer;
	node = (XMLNode*)nodePointer;

#ifdef _DEBUG
	printf("[XML] Deleting node...\n");
#endif
	doc->DeleteNode(node);

	sq->pushnull(v);
	return 0;
}

_SQUIRRELDEF(XML_Test)
{
	XMLDocument* doc = NULL;
	return 0;
}

_SQUIRRELDEF(XML_RootElement)
{
	SQUserPointer docPointer = NULL;
	XMLDocument* doc = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &docPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.RootElement': Called without instance"));;
	}
	doc = (XMLDocument*)docPointer;

#ifdef _DEBUG
	printf("[XML] Getting RootElement\n");
#endif
	XMLElement* element = doc->RootElement();

	if (element != nullptr)
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XML.RootElement': Root Element not found!"));
	}

	SquirrelCreateClassInstance(v, "XMLElement", element);
	return 1;
}