#include "ProductNode.h"

Product ProductNode::getNode()
{
	return this->Node;
}

void ProductNode::setNode(Product Product)
{
	this->Node = Product;
}

ProductNode* ProductNode::getNext()
{
	return this->pNext;
}

void ProductNode::setNext(ProductNode* pNext)
{
	this->pNext = pNext;
}



