#pragma once
#include <iostream>
#include <fstream>

class Product {
private:
	std::string name;
	std::string category;
	std::string shop;
	double price;
public:
	std::string getName();
	std::string getCategory();
	std::string getShop();
	double getPrice();
	bool isSame(Product);
	bool operator==(Product);
	static Product loadProduct();
	static Product loadProduct(std::string shop);
	static Product loadProductFromFile(std::ifstream& file);
	Product(std::string name, std::string category, std::string shop, double price) : name(name), category(category), shop(shop), price(price) {};
};