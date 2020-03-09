#pragma once
#include "ProductList.h"
#include "Date.h"
#include "MemberList.h"

class Transaction {
private:
	Date date;
	Member member;
	double price;
	ProductList* PurchaseList;
	std::string shop;
public:
	Transaction(Date date, Member member, double price, ProductList* PurchaseList, std::string shop) : date(date),
		member(member), price(price), PurchaseList(PurchaseList), shop(shop) {};
	Transaction loadTransaction(MemberList& members, ProductList& products);
	static Transaction loadTransactionFromFile(std::ifstream& file);

	Member getMember();
	Date getDate();
	double getPrice();
	ProductList* getPurchaseList();
	std::string getShop();
};
