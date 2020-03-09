#pragma once
#include "Product.h"

class ProductNode
{
private:
	Product Node;
	ProductNode* pNext;

public:
	ProductNode* getNext();
	ProductNode(Product Node) :Node(Node), pNext(nullptr) {};
	ProductNode(Product Node, ProductNode* pNext) :Node(Node), pNext(pNext) {};
	Product getNode();
	void setNode(Product);
	void setNext(ProductNode*);
};