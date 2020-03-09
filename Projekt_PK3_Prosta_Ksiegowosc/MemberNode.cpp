#include "MemberNode.h"

Member MemberNode::getNode()
{
	return this->Node;
}

void MemberNode::setNode(Member member)
{
	this->Node = member;
}

MemberNode* MemberNode::getNext()
{
	return this->pNext;
}

void MemberNode::setNext(MemberNode* pNext)
{
	this->pNext = pNext;
}