#include "Product.h"


std::string Product::getName()
{
	return this->name;
}

std::string Product::getShop()
{
	return this->shop;
}

std::string Product::getCategory()
{
	return this->category;
}

double Product::getPrice()
{
	return this->price;
}

bool Product::isSame(Product product)
{
	if (this->getName().compare(product.getName()) == 0 && this->getCategory().compare(product.getCategory()) == 0
		&& this->getShop().compare(product.getShop()) == 0 && this->getPrice() == product.getPrice())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Product::operator==(Product product)
{
	if (this->isSame(product) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}



Product Product::loadProduct()
{
	std::cout << "Write name of the Product: \n";
	std::string name_written;
	std::cin >> name_written;

	std::cout << "Write category of the Product\n";
	std::string category_written;
	std::cin >> category_written;

	std::cout << "Write which shop was the product in\n";
	std::string shop_written;
	std::cin >> shop_written;

	std::cout << "Write price of the product: \n";
	double price_written;
	std::cin >> price_written;

	Product Product(name_written, category_written, shop_written, price_written);
	return Product;
}


Product Product::loadProduct(std::string shop)
{
	std::cout << "Write name of the Product: \n";
	std::string name_written;
	std::cin >> name_written;

	std::cout << "Write category of the Product\n";
	std::string category_written;
	std::cin >> category_written;

	std::cout << "Write price of the product: \n";
	double price_written;
	std::cin >> price_written;


	Product Product(name_written, category_written, shop, price_written);
	return Product;
}

Product Product::loadProductFromFile(std::ifstream& file)
{
	std::string name;
	std::string category;
	std::string shop;
	double price;
	file >> name >> category >> shop >> price;

	Product Product(name, category, shop, price);
	return Product;
}

