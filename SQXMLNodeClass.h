#pragma once

_SQUIRRELDEF(XMLNode_InsertFirstChild)
{
	SQUserPointer parentNodePointer = NULL;
	SQUserPointer addNodePointer = NULL;
	XMLNode* parentNode = NULL;
	XMLNode* addNode = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &parentNodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.InsertFirstChild': Called without instance"));
	}
	sq->getinstanceup(v, 2, &addNodePointer, NULL);
	parentNode = (XMLNode*)parentNodePointer;
	addNode = (XMLNode*)addNodePointer;

#ifdef _DEBUG
	printf("[XML] Inserting first child...\n");
#endif
	parentNode->InsertFirstChild(addNode);
	sq->push(v, 2);
	return 1;
}

_SQUIRRELDEF(XMLNode_InsertEndChild)
{
	SQUserPointer parentNodePointer = NULL;
	SQUserPointer addNodePointer = NULL;
	XMLNode* parentNode = NULL;
	XMLNode* addNode = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &parentNodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.InsertEndChild': Called without instance"));
	}
	sq->getinstanceup(v, 2, &addNodePointer, NULL);
	parentNode = (XMLNode*)parentNodePointer;
	addNode = (XMLNode*)addNodePointer;

#ifdef _DEBUG
	printf("[XML] Inserting End child...\n");
#endif
	parentNode->InsertEndChild(addNode);
	sq->push(v, 2);
	return 1;
}

_SQUIRRELDEF(XMLNode_InsertAfterChild)
{
	SQUserPointer parentNodePointer = NULL;
	SQUserPointer addNodePointer = NULL;
	SQUserPointer afterThisNodePointer = NULL;
	XMLNode* parentNode = NULL;
	XMLNode* addNode = NULL;
	XMLNode* afterThisNode = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &parentNodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.InsertEndChild': Called without instance"));
	}
	sq->getinstanceup(v, 2, &afterThisNodePointer, NULL);
	sq->getinstanceup(v, 3, &addNodePointer, NULL);
	parentNode = (XMLNode*)parentNodePointer;
	addNode = (XMLNode*)addNodePointer;
	afterThisNode = (XMLNode*)afterThisNodePointer;

#ifdef _DEBUG
	printf("[XML] Inserting after child...\n");
#endif
	parentNode->InsertAfterChild(afterThisNode, addNode);
	sq->push(v, 2);
	return 1;
}

_SQUIRRELDEF(XMLNode_Value)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.Value': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	const char* value = node->Value();
#ifdef _DEBUG
	printf("[XML] XMLNode Value: \"%s\"...\n", value);
#endif
	sq->pushstring(v, value, -1);
	return 1;
}

_SQUIRRELDEF(XMLNode_SetValue)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;
	const SQChar* text = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.Value': Called without instance"));
	}
	node = (XMLNode*)nodePointer;
	sq->getstring(v, 2, &text);

#ifdef _DEBUG
	printf("[XML] XMLNode Set Value: \"%s\"...\n", text);
#endif
	node->SetValue(text);
	sq->pushnull(v);
	return 0;
}

_SQUIRRELDEF(XMLNode_GetLineNumber)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.GetLineNumber': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	int lineNumber = node->GetLineNum();
#ifdef _DEBUG
	printf("[XML] XMLNode GetLineNumber: \"%i\"...\n", lineNumber);
#endif
	sq->pushinteger(v, lineNumber);
	return 1;
}

_SQUIRRELDEF(XMLNode_Parent)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.Parent': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	XMLNode* parentNode = node->Parent();
#ifdef _DEBUG
	printf("[XML] XMLNode Parent...\n");
#endif

	SquirrelCreateClassInstance(v, "XMLNode", parentNode);
	return 1;
}

_SQUIRRELDEF(XMLNode_NoChildren)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.NoChildren': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	bool noChildren = node->NoChildren();
#ifdef _DEBUG
	printf("[XML] XMLNode NoChildren: \"%s\"...\n", noChildren ? "true" : "false");
#endif
	sq->pushbool(v, noChildren);
	return 1;
}

_SQUIRRELDEF(XMLNode_FirstChild)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.FirstChild': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	XMLNode* firstChild = node->FirstChild();
#ifdef _DEBUG
	printf("[XML] XMLNode FirstChild...\n");
#endif

	if (firstChild == NULL)
	{
		sq->pushnull(v);
	}
	else
	{
		SquirrelCreateClassInstance(v, "XMLNode", firstChild);
	}
	return 1;
}

_SQUIRRELDEF(XMLNode_FirstChildElement)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.FirstChildElement': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	const SQChar* elementName = NULL;
	XMLElement* firstChildElement = NULL;
	if (sq->gettop(v) == 2 && sq->gettype(v, 2) == OT_STRING)
	{
		sq->getstring(v, 2, &elementName);
#ifdef _DEBUG
		printf("[XML] XMLNode FirstChildElement: \"%s\"...\n", elementName);
#endif
		firstChildElement = node->FirstChildElement(elementName);
	}
	else
	{
#ifdef _DEBUG
		printf("[XML] XMLNode FirstChildElement...\n");
#endif
		firstChildElement = node->FirstChildElement();
	}

	if (firstChildElement == NULL)
	{
		sq->pushnull(v);
	}
	else
	{
		SquirrelCreateClassInstance(v, "XMLElement", firstChildElement);
	}
	return 1;
}

_SQUIRRELDEF(XMLNode_LastChild)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.LastChild': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	XMLNode* lastChild = node->LastChild();
#ifdef _DEBUG
	printf("[XML] XMLNode LastChild...\n");
#endif

	if (lastChild == NULL)
	{
		sq->pushnull(v);
	}
	else
	{
		SquirrelCreateClassInstance(v, "XMLNode", lastChild);
	}
	return 1;
}

_SQUIRRELDEF(XMLNode_LastChildElement)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.LastChildElement': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	const SQChar* elementName = NULL;
	XMLElement* lastChildElement = NULL;
	if (sq->gettop(v) == 2 && sq->gettype(v, 2) == OT_STRING)
	{
		sq->getstring(v, 2, &elementName);
#ifdef _DEBUG
		printf("[XML] XMLNode LastChildElement: \"%s\"...\n", elementName);
#endif
		lastChildElement = node->LastChildElement(elementName);
	}
	else
	{
#ifdef _DEBUG
		printf("[XML] XMLNode LastChildElement...\n");
#endif
		lastChildElement = node->LastChildElement();
	}

	if (lastChildElement == NULL)
	{
		sq->pushnull(v);
	}
	else
	{
		SquirrelCreateClassInstance(v, "XMLElement", lastChildElement);
	}
	return 1;
}

_SQUIRRELDEF(XMLNode_PreviousSibling)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.PreviousSibling': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	XMLNode* previousSibling = node->PreviousSibling();
#ifdef _DEBUG
	printf("[XML] XMLNode PreviousSibling...\n");
#endif

	if (previousSibling == NULL)
	{
		sq->pushnull(v);
	}
	else
	{
		SquirrelCreateClassInstance(v, "XMLNode", previousSibling);
	}
	return 1;
}

_SQUIRRELDEF(XMLNode_PreviousSiblingElement)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.PreviousSiblingElement': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	const SQChar* elementName = NULL;
	XMLElement* previousSiblingElement = NULL;
	if (sq->gettop(v) == 2 && sq->gettype(v, 2) == OT_STRING)
	{
		sq->getstring(v, 2, &elementName);
#ifdef _DEBUG
		printf("[XML] XMLNode PreviousSiblingElement: \"%s\"...\n", elementName);
#endif
		previousSiblingElement = node->PreviousSiblingElement(elementName);
	}
	else
	{
#ifdef _DEBUG
		printf("[XML] XMLNode PreviousSiblingElement...\n");
#endif
		previousSiblingElement = node->PreviousSiblingElement();
	}

	if (previousSiblingElement == NULL)
	{
		sq->pushnull(v);
	}
	else
	{
		SquirrelCreateClassInstance(v, "XMLElement", previousSiblingElement);
	}
	return 1;
}

_SQUIRRELDEF(XMLNode_NextSibling)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.NextSibling': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	XMLNode* nextSibling = node->NextSibling();
#ifdef _DEBUG
	printf("[XML] XMLNode PreviousSibling...\n");
#endif

	if (nextSibling == NULL)
	{
		sq->pushnull(v);
	}
	else
	{
		SquirrelCreateClassInstance(v, "XMLNode", nextSibling);
	}
	return 1;
}

_SQUIRRELDEF(XMLNode_NextSiblingElement)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.NextSiblingElement': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

	const SQChar* elementName = NULL;
	XMLElement* nextSiblingElement = NULL;
	if (sq->gettop(v) == 2 && sq->gettype(v, 2) == OT_STRING)
	{
		sq->getstring(v, 2, &elementName);
#ifdef _DEBUG
		printf("[XML] XMLNode NextSiblingElement: \"%s\"...\n", elementName);
#endif
		nextSiblingElement = node->NextSiblingElement(elementName);
	}
	else
	{
#ifdef _DEBUG
		printf("[XML] XMLNode NextSiblingElement...\n");
#endif
		nextSiblingElement = node->NextSiblingElement();
	}

	if (nextSiblingElement == NULL)
	{
		sq->pushnull(v);
	}
	else
	{
		SquirrelCreateClassInstance(v, "XMLElement", nextSiblingElement);
	}
	return 1;
}

_SQUIRRELDEF(XMLNode_DeleteChildren)
{
	SQUserPointer nodePointer = NULL;
	XMLNode* node = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &nodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.DeleteChildren': Called without instance"));
	}
	node = (XMLNode*)nodePointer;

#ifdef _DEBUG
	printf("[XML] XMLNode DeleteChildren...\n");
#endif
	node->DeleteChildren();

	sq->pushnull(v);
	return 0;
}
_SQUIRRELDEF(XMLNode_DeleteChild)
{
	SQUserPointer parentNodePointer = NULL;
	SQUserPointer addNodePointer = NULL;
	XMLNode* parentNode = NULL;
	XMLNode* deleteNode = NULL;

	if (SQ_FAILED(sq->getinstanceup(v, 1, &parentNodePointer, NULL)))
	{
		sq->pushnull(v);
		return sq->throwerror(v, _SC("Error in 'XMLNode.DeleteChild': Called without instance"));
	}
	sq->getinstanceup(v, 2, &addNodePointer, NULL);
	parentNode = (XMLNode*)parentNodePointer;
	deleteNode = (XMLNode*)addNodePointer;

#ifdef _DEBUG
	printf("[XML] Node delete child...\n");
#endif
	parentNode->DeleteChild(deleteNode);
	sq->pushnull(v);
	return 0;
}
