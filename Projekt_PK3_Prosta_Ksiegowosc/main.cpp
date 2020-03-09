#include "Statistics.h"

int main()
{
	MemberList members;
	ProductList products;
	TransactionList transactions;
	Statistics statistics;
	members.loadFromFile();
	products.loadFromFile();
	transactions.loadFromFile();

	std::cout << "What do you want to do?\n 1 - Add member\n 2 - Print members\n 3 - Add product\n 4 - Print products";
	std::cout << "\n 5 - Add transaction\n 6 - Print transactions\n 7 - Statistics\n 8 - Exit\n";
	int choice;
	int choice2;

	do
	{ 
		std::cin >> choice;
		switch (choice)
		{
		case 1: members.addNode();
			members.printToFile();
			break;
		case 2: members.print();
			break;
		case 3: products.addNode();
			products.printToFile();
			break;
		case 4: products.print();
			break;
		case 5: transactions.addNode(members, products);
			transactions.printToFile();
			members.printToFile();
			products.printToFile();
			break;
		case 6: transactions.print();
			break;
		case 7: std::cout << " What statistics to you want to see:\n 1- Statistics of everything\n 2- Statistics of one member";
			std::cout << "\n 3- Statistics between two dates\n 4- Statistics of one member between two dates\n 5- Exit\n";
			std::cin >> choice2;
			while (choice2 != 1 && choice2 != 2 && choice2 != 3 && choice2 != 4 && choice2 != 5)
			{
				std::cout << "Choose a number between 1 and 4!\n";
				std::cin >> choice2;
			}
			if (choice2 == 1)
			{
				statistics.countSum(transactions.getHead());
				statistics.countMean(transactions.getHead());
				statistics.countMedian(transactions.getHead());
				statistics.countStandardDeviation(transactions.getHead());
				statistics.print();
			}
			else if(choice2 == 2)
			{
				Member member = Member::loadMember();
				statistics.countSum(transactions.getHead(), member);
				statistics.countMean(transactions.getHead(), member);
				statistics.countMedian(transactions.getHead(), member);
				statistics.countStandardDeviation(transactions.getHead(), member);
				statistics.print();
			}
			else if (choice2 == 3)
			{
				std::cout << "\nWrite the start date:\n";
				Date start;
				std::cout << "\nWrite the end date:\n";
				Date end;
				statistics.countSum(transactions.getHead(), start, end);
				statistics.countMean(transactions.getHead(), start, end);
				statistics.countMedian(transactions.getHead(), start, end);
				statistics.countStandardDeviation(transactions.getHead(), start, end);
				statistics.print();
			}
			else if (choice2 == 4)
			{
				Member member = Member::loadMember();
				std::cout << "\nWrite the start date:\n";
				Date start;
				std::cout << "\nWrite the end date:\n";
				Date end;
				statistics.countSum(transactions.getHead(), member, start, end);
				statistics.countMean(transactions.getHead(),member, start, end);
				statistics.countMedian(transactions.getHead(),member, start, end);
				statistics.countStandardDeviation(transactions.getHead(),member, start, end);
				statistics.print();
			}
			else if (choice2 == 5)
			{
				break;
			}
			break;
		}
		system("pause");
		system("CLS");
		std::cout << "What do you want to do?\n 1- Add member\n 2- Print members\n 3- Add product\n 4- Print products";
		std::cout << "\n 5 - Add transaction\n 6 - Print transactions\n 7 - Statistics\n 8 - Exit\n";
	} while (choice != 8);


	
	return 0;
}