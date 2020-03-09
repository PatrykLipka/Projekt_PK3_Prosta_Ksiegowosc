#include "Transaction.h"

Member Transaction::getMember()
{
	return this->member;
}

Date Transaction::getDate()
{
	return this->date;
}

double Transaction::getPrice()
{
	return this->price;
}

ProductList* Transaction::getPurchaseList()
{
	return this->PurchaseList;
}

std::string Transaction::getShop()
{
	return this->shop;
}

Transaction Transaction::loadTransaction(MemberList& members, ProductList& products)
{
	Member member = Member::loadMember();
	if (!members.isInList(member))
	{
		members.addNode(member, members);
	}

	Date date;

	std::string shop;
	std::cout << "Write in which shop the purchase took place: \n";
	std::cin >> shop;

	int choice = 1;
	ProductList* bought=new ProductList;


	while (choice != 0)
	{
		std::cout << "Write the amount of product you want to add: \n";
		int amount;
		std::cin >> amount;
		bought->addNode(products, shop, amount);
		std::cout << "Do you want to add an item to the purchase list?\n1-yes\n0-no\n";
		std::cin >> choice;
	}
	
	ProductNode* temp = bought->getHead();

	double prices = 0;
	while (temp)
	{
		prices += temp->getNode().getPrice();
		temp = temp->getNext();
	}
	
	Transaction transaction(date, member,prices, bought , shop);
	return transaction;
}


Transaction Transaction::loadTransactionFromFile(std::ifstream& file)
{
	Member member = Member::loadMemberFromFile(file);

	double price;

	file >> price;

	int day;
	int month;
	int year;

	file >> day >> month >> year;

	Date date(day,month,year);

	std::string shop;
	file >> shop;

	

	ProductList* bought = new ProductList;

	std::string test;

	while (file >> test)
	{
		if (test.compare("Transaction") == 0)
		{
			break;
		}
		else
		{
			for (int i = 0; i < test.length(); i++)
			{
				file.unget();
			}
			bought->addNodeFromFile(file);
		}
	}


	ProductNode* temp = bought->getHead();

	

	Transaction transaction(date, member, price, bought, shop);
	return transaction;
}