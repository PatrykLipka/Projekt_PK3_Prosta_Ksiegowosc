#pragma once
#include "TransactionNode.h"

class TransactionList {
private:
	TransactionNode* pHead;

public:
	TransactionList();
	~TransactionList();
	TransactionNode* getHead();
	void setHead(TransactionNode*);
	void loadFromFile();
	void addNode(MemberList& members, ProductList& products);
	void addNodeFromFile(std::ifstream&);
	void print();
	void printToFile();
};
