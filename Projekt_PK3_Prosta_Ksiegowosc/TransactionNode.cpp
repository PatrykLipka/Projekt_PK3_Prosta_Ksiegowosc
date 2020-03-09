#include "TransactionNode.h"


Transaction TransactionNode::getNode()
{
	return this->Node;
}

void TransactionNode::setNode(Transaction Transaction)
{
	this->Node = Transaction;
}

TransactionNode* TransactionNode::getNext()
{
	return this->pNext;
}

void TransactionNode::setNext(TransactionNode* pNext)
{
	this->pNext = pNext;
}