#pragma once
#include "Transaction.h"

class TransactionNode
{
private:
	Transaction Node;
	TransactionNode* pNext;

public:
	TransactionNode* getNext();
	TransactionNode(Transaction Node) :Node(Node), pNext(nullptr) {};
	TransactionNode(Transaction Node, TransactionNode* pNext) :Node(Node), pNext(pNext) {};
	Transaction getNode();
	void setNode(Transaction);
	void setNext(TransactionNode*);
};