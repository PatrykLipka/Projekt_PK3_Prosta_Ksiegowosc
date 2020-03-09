#include "TransactionList.h"


TransactionList::TransactionList()
{
	
	this->pHead = nullptr;
}

TransactionList::~TransactionList()
{
	while (pHead)
	{
		TransactionNode* temp = pHead->getNext();
		delete pHead->getNode().getPurchaseList();
		delete pHead;
		pHead = temp;
	}
}

TransactionNode* TransactionList::getHead()
{
	return this->pHead;
}

void TransactionList::setHead(TransactionNode* pHead)
{
	this->pHead = pHead;
}


void TransactionList::addNode(MemberList& members, ProductList& products)
{
	if (!pHead)
	{
		Transaction transaction = transaction.loadTransaction(members, products);
		TransactionNode* Node = new TransactionNode(transaction);
		pHead = Node;
	}
	else {
		Transaction transaction = transaction.loadTransaction(members, products);
		TransactionNode* Node = new TransactionNode(transaction, pHead);
		pHead = Node;
	}
}


void TransactionList::print()
{
	TransactionNode* temp;
	if (pHead)
	{
		temp = pHead;
	}
	else {
		std::cout << "Nothing to print!\n";
		return;
	}
	ProductList* products = temp->getNode().getPurchaseList();
	int amount = 1;
	while (temp)
	{
		std::cout << "Transaction " << amount << std::endl;
		std::cout << "Name: " << temp->getNode().getMember().getName() 
			<< std::endl<< "Position: " << temp->getNode().getMember().getPosition() 
			<< std::endl<< "Date: "; temp->getNode().getDate().print();
		std::cout << "Shop: " << temp->getNode().getShop() 
			<< std::endl<< "Price: "<< temp->getNode().getPrice() 
			<< std::endl << std::endl << "Bought: \n"; 
		temp->getNode().getPurchaseList()->printWithAmount();

		amount++;
		std::cout << std::endl << std::endl;
		temp = temp->getNext();
	}
}

void TransactionList::addNodeFromFile(std::ifstream& file)
{
	if (!pHead)
	{
		Transaction transaction = transaction.loadTransactionFromFile(file);
		TransactionNode* Node = new TransactionNode(transaction);
		pHead = Node;
	}
	else {
		Transaction transaction = transaction.loadTransactionFromFile(file);
		TransactionNode* Node = new TransactionNode(transaction, pHead);
		pHead = Node;
	}
}

void TransactionList::loadFromFile()
{
	std::ifstream file;
	file.open("TransactionList.txt");
	if (file.good())
	{
		while (!file.eof())
		{
			addNodeFromFile(file);
		}
	}
	file.close();
}
 

void TransactionList::printToFile()
{
	std::ofstream file;
	file.open("TransactionList.txt");
	TransactionNode* temp;
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
			
			file << temp->getNode().getMember().getName() << " " << temp->getNode().getMember().getPosition() << " "<< temp->getNode().getPrice()<<" " << temp->getNode().getDate().getDay() << " " << temp->getNode().getDate().getMonth() << " " << temp->getNode().getDate().getYear() << " " << temp->getNode().getShop() << " ";
			temp->getNode().getPurchaseList()->printInLine(file);
			file << std::endl << "Transaction" << std::endl;
		}
		else
		{
			file << temp->getNode().getMember().getName() << " " << temp->getNode().getMember().getPosition() << " " << temp->getNode().getPrice() << " " << temp->getNode().getDate().getDay() << " " << temp->getNode().getDate().getMonth() << " " << temp->getNode().getDate().getYear() << " " << temp->getNode().getShop() << " ";
			temp->getNode().getPurchaseList()->printInLine(file);
			file << std::endl << "Transaction";
		}
		temp = temp->getNext();
	}
	file.close();
}
