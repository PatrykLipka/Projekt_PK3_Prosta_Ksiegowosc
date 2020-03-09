#include "ProductList.h"

ProductList::ProductList()
{
	this->pHead = nullptr;
}

ProductList::~ProductList()
{
	while (pHead)
	{
		ProductNode* temp = pHead->getNext();
		delete pHead;
		pHead = temp;
	}
}

ProductNode* ProductList::getHead()
{
	return this->pHead;
}


bool ProductList::isInList(Product product)
{
	ProductNode* temp = pHead;
	while (temp)
	{
		if (temp->getNode()==product)
		{
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

int ProductList::howManyInList(Product product)
{
	ProductNode* temp = pHead;
	int amount=0;
	while (temp)
	{
		if (temp->getNode() == product)
		{
			amount++;
		}
		temp = temp->getNext();
	}
	return amount;
}

void ProductList::addNode()
{
	if (!pHead)
	{
		Product product = Product::loadProduct();
		ProductNode* Node = new ProductNode(product);
		pHead = Node;
	}
	else {
		Product product = Product::loadProduct();
		if (!isInList(product))
		{
			ProductNode* Node = new ProductNode(product, pHead);
			pHead = Node;
		}
		else {
			std::cout << "Product already on the list!\n";
		}
	}
}

void ProductList::addNodeFromFile(std::ifstream& file)
{
	if (!pHead)
	{
		Product product = Product::loadProductFromFile(file);
		ProductNode* Node = new ProductNode(product);
		pHead = Node;
	}
	else {
		Product product = Product::loadProductFromFile(file);
			ProductNode* Node = new ProductNode(product, pHead);
			pHead = Node;
	}
}


void ProductList::setHead(ProductNode* Node)
{
	this->pHead = Node;
}

void ProductList::addNode(Product product, ProductList& products)
{
	if (!pHead)
	{
		ProductNode* Node = new ProductNode(product);
		products.setHead(Node);
		pHead=Node;
	}
	else {
		if (!isInList(product))
		{
			ProductNode* Node = new ProductNode(product, pHead);
			products.setHead(Node);
		}
		else {
			std::cout << "Product already on the list!\n";
		}
	}
}

void ProductList::addNode(ProductList& products, std::string shop, int amount)
{
	Product product = Product::loadProduct(shop);
	if (!products.isInList(product))
	{
		products.addNode(product, products);
	}
	if (!pHead)
	{
		amount--;
		ProductNode* Node = new ProductNode(product);
		pHead = Node;
		for (int i = 0; i < amount; i++)
		{
			ProductNode* Node = new ProductNode(product, pHead);
			pHead = Node;
		}
	}
	else 
	{
		for(int i=0; i<amount; i++)
		{
			ProductNode* Node = new ProductNode(product, pHead);
			pHead = Node;
		}
	}
}


void ProductList::print()
{
	ProductNode* temp;
	if (pHead)
	{
		temp = pHead;
	}
	else {
		std::cout << "Nothing to print!\n";
		return;
	}
	while (temp)
	{
		std::cout << "Name: " << temp->getNode().getName() << std::endl;
		std::cout << "Category: " << temp->getNode().getCategory() << std::endl;
		std::cout << "Shop: " << temp->getNode().getShop() << std::endl;
		std::cout << "Price: "<< temp->getNode().getPrice();

		std::cout << std::endl << std::endl;
		temp = temp->getNext();
	}
}

bool ProductList::wasItBefore(ProductNode* Node)
{
	ProductNode* temp = pHead;
	while (temp != Node)
	{
		if (temp->getNode().isSame(Node->getNode()))
		{
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

void ProductList::printWithAmount()
{
	ProductNode* temp;
	int amount = 0;
	if (pHead)
	{
		temp = pHead;
	}
	else {
		std::cout << "Nothing to print!\n";
		return;
	}
	while (temp)
	{
		if(!this->wasItBefore(temp))
		{
		amount = howManyInList(temp->getNode());
		std::cout << "Name: " << temp->getNode().getName() << std::endl;
		std::cout << "Category: " << temp->getNode().getCategory() << std::endl;
		std::cout << "Amount of this product: " << amount << std::endl;
		std::cout << "Price for all: " << amount * temp->getNode().getPrice() << std::endl;
		std::cout << "Price for one: " << temp->getNode().getPrice();

		std::cout << std::endl << std::endl;
		}
		temp = temp->getNext();
	}
}


void ProductList::loadFromFile()
{
	std::ifstream file;
	file.open("ProductList.txt");
	if(file.good())
	{ 
		while (!file.eof())
		{
			addNodeFromFile(file);
		}
	}
	file.close();
}

void ProductList::printToFile()
{
	std::ofstream file;
	file.open("ProductList.txt");
	ProductNode* temp;
	if (pHead)
	{
		temp = pHead;
	}
	else
	{
		return;
	}
	while (temp)
	{
		if (temp->getNext())
		{
			file << temp->getNode().getName() << " " << temp->getNode().getCategory() << " " << temp->getNode().getShop() << " " << temp->getNode().getPrice() << std::endl;
		}
		else
		{
			file << temp->getNode().getName() << " " << temp->getNode().getCategory() << " " << temp->getNode().getShop() << " " << temp->getNode().getPrice();
		}
		temp = temp->getNext();
	}
	file.close();
}

void ProductList::printInLine(std::ofstream& file)
{
	ProductNode* temp;
	if (pHead)
	{
		temp = pHead;
	}
	else
	{
		return;
	}
	while (temp)
	{
		if(temp->getNext())
		{
			file << temp->getNode().getName() << " " << temp->getNode().getCategory() << " " << temp->getNode().getShop() << " " << temp->getNode().getPrice()<<" ";
		}	
		else
		{
			file << temp->getNode().getName() << " " << temp->getNode().getCategory() << " " << temp->getNode().getShop() << " " << temp->getNode().getPrice();
		}
		temp = temp->getNext();
	}
}