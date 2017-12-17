#pragma once

_SQUIRRELDEF(XMLElement_Attribute)
{
	SQUserPointer elementPointer = NULL;
	XMLElement* element = NULL;
	const SQChar* attributeName = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &elementPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLElement.Attribute': Called without instance"));
	}
	element = (XMLElement*)elementPointer;
	sq->getstring(v, 2, &attributeName);

#ifdef _DEBUG
	printf("[XML] Getting Attribute: %s...\n", attributeName);
#endif
	const SQChar* attribute = NULL;
	attribute = element->Attribute(attributeName);
	if (attribute == NULL)
	{
		sq->pushnull(v);
	}
	else
	{
		sq->pushstring(v, attribute, -1);
	}
	return 1;
}

_SQUIRRELDEF(XMLElement_IntegerAttribute)
{
	SQUserPointer elementPointer = NULL;
	XMLElement* element = NULL;
	const SQChar* attributeName = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &elementPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLElement.IntegerAttribute': Called without instance"));
	}
	element = (XMLElement*)elementPointer;
	sq->getstring(v, 2, &attributeName);

#ifdef _DEBUG
	printf("[XML] Getting IntegerAttribute: %s...\n", attributeName);
#endif
	SQInteger attribute = NULL;
	XMLError error = element->QueryIntAttribute(attributeName, &attribute);
	if (error != XML_SUCCESS)
	{
		sq->pushnull(v);
	}
	else
	{
		sq->pushinteger(v, attribute);
	}
	return 1;
}

_SQUIRRELDEF(XMLElement_FloatAttribute)
{
	SQUserPointer elementPointer = NULL;
	XMLElement* element = NULL;
	const SQChar* attributeName = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &elementPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLElement.FloatAttribute': Called without instance"));
	}
	element = (XMLElement*)elementPointer;
	sq->getstring(v, 2, &attributeName);

#ifdef _DEBUG
	printf("[XML] Getting FloatAttribute: %s...\n", attributeName);
#endif
	SQFloat attribute = NULL;
	XMLError error = element->QueryFloatAttribute(attributeName, &attribute);
	if (error != XML_SUCCESS)
	{
		sq->pushnull(v);
	}
	else
	{
		sq->pushfloat(v, attribute);
	}
	return 1;
}

_SQUIRRELDEF(XMLElement_BoolAttribute)
{
	SQUserPointer elementPointer = NULL;
	XMLElement* element = NULL;
	const SQChar* attributeName = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &elementPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLElement.BoolAttribute': Called without instance"));
	}
	element = (XMLElement*)elementPointer;
	sq->getstring(v, 2, &attributeName);

#ifdef _DEBUG
	printf("[XML] Getting BoolAttribute: %s...\n", attributeName);
#endif
	bool attribute = NULL;
	XMLError error = element->QueryBoolAttribute(attributeName, &attribute);
	if (error != XML_SUCCESS)
	{
		sq->pushnull(v);
	}
	else
	{
		sq->pushbool(v, attribute);
	}
	return 1;
}

_SQUIRRELDEF(XMLElement_SetAttribute)
{
	SQUserPointer elementPointer = NULL;
	XMLElement* element = NULL;
	const SQChar* attributeName = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &elementPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLElement.SetAttribute': Called without instance"));
	}
	element = (XMLElement*)elementPointer;
	if (sq->gettop(v) == 3)
	{
		sq->getstring(v, 2, &attributeName);
#ifdef _DEBUG
		printf("[XML] Getting SetAttribute: %s...\n", attributeName);
#endif
		switch (sq->gettype(v, 3))
		{
		case OT_BOOL:
		{
			SQBool booleanValue = NULL;
			sq->getbool(v, 3, &booleanValue);
			element->SetAttribute(attributeName, booleanValue);
		}
			break;
		case OT_FLOAT:
		{
			SQFloat floatValue = NULL;
			sq->getfloat(v, 3, &floatValue);
			element->SetAttribute(attributeName, floatValue);
		}
			break;
		case OT_STRING:
		{
			const SQChar* stringValue = NULL;
			sq->getstring(v, 3, &stringValue);
			element->SetAttribute(attributeName, stringValue);
		}
			break;
		case OT_INTEGER:
		{
			SQInteger intValue = NULL;
			sq->getinteger(v, 3, &intValue);
			element->SetAttribute(attributeName, intValue);
		}
			break;
		}
	}

	sq->pushnull(v);
	return 0;
}

_SQUIRRELDEF(XMLElement_GetText)
{
	SQUserPointer elementPointer = NULL;
	XMLElement* element = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &elementPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLElement.GetText': Called without instance"));
	}
	element = (XMLElement*)elementPointer;

#ifdef _DEBUG
	printf("[XML] Getting Text...\n");
#endif
	const SQChar* text = NULL;
	text = element->GetText();
	if (text == NULL)
	{
		sq->pushnull(v);
	}
	else
	{
		sq->pushstring(v, text, -1);
	}
	return 1;
}

_SQUIRRELDEF(XMLElement_SetText)
{
	SQUserPointer elementPointer = NULL;
	XMLElement* element = NULL;
	const SQChar* text = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &elementPointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLElement.SetText': Called without instance"));
	}
	element = (XMLElement*)elementPointer;
	sq->getstring(v, 2, &text);

#ifdef _DEBUG
	printf("[XML] Setting text: %s...\n", text);
#endif
	element->SetText(text);
	return 1;
}