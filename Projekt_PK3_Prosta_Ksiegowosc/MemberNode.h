#pragma once
#include "Member.h"

class MemberNode
{
private:
	Member Node;
	MemberNode* pNext;

public:
	MemberNode* getNext();
	MemberNode(Member Node) :Node(Node), pNext(nullptr) {};
	MemberNode(Member Node, MemberNode* pNext) :Node(Node), pNext(pNext) {};
	Member getNode();
	void setNode(Member);
	void setNext(MemberNode*);
};