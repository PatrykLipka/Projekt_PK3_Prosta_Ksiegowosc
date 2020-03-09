#pragma once
#include "ProductNode.h"

class ProductList {
private:
	ProductNode* pHead;

public:
	ProductList();
	~ProductList();
	ProductNode* getHead();
	void setHead(ProductNode*);
	void addNode();
	void addNode(Product, ProductList&);
	void addNode(ProductList&,std::string shop, int amount);
	void addNodeFromFile(std::ifstream&);
	bool isInList(Product);
	bool wasItBefore(ProductNode* Node);
	int howManyInList(Product);
	void print();
	void printWithAmount();

	void printToFile();
	void printInLine(std::ofstream&);
	void loadFromFile();
};
