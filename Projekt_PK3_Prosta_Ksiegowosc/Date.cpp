#include "Date.h"

bool Date::operator <=(Date date)
{
	if (this->getYear() < date.getYear())
	{
		return true;
	}
	else
	{
		if (this->getYear() == date.getYear() && this->getMonth() < date.getMonth())
		{
			return true;
		}
		else
		{
			if (this->getYear() == date.getYear() && this->getMonth() == date.getMonth() && this->getDay() <= date.getDay())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}
bool Date::operator >=(Date date)
{
	if (this->getYear() > date.getYear())
	{
		return true;
	}
	else
	{
		if (this->getYear() == date.getYear() && this->getMonth() > date.getMonth())
		{
			return true;
		}
		else
		{
			if (this->getYear() == date.getYear() && this->getMonth() == date.getMonth() && this->getDay() >= date.getDay())
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Date::isLeapYear()
{
	if ((getYear() % 4 == 0 && getYear() % 100 != 0) || getYear() % 400 == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

void Date::setYear(int year)
{
	this->year = year;
}

int Date::getYear()
{
	return this->year;
}

void Date::setMonth(int month)
{
	if (1 <= month && month <= 12)
	{
		this->month = month;
	}
	else {
		std::cout << "Wrong month! Write a number between 1 and 12.\n";
		this->month = -1;
	}
}

int Date::getMonth()
{
	return this->month;
}

void Date::setDay(int day)
{
	if (getMonth() == 1 || getMonth() == 3 || getMonth() == 5 || getMonth() == 7 || getMonth() == 8 || getMonth() == 10 || getMonth() == 12)
	{
		if (1 <= day && day <= 31)
		{
			this->day = day;
		}
		else {
			std::cout << "Wrong number of days! Write a number between 1 and 31.\n";
			this->day = -1;
		}
	}
	else if (getMonth() == 4 || getMonth() == 6 || getMonth() == 9 || getMonth() == 11)
	{
		if (1 <= day && day <= 30)
		{
			this->day = day;
		}
		else {
			std::cout << "Wrong number of days! Write a number between 1 and 30.\n";
			this->day = -1;
		}
	}
	else
	{
		if (this->isLeapYear())
		{
			if (1 <= day && day <= 29)
			{
				this->day = day;
			}
			else {
				std::cout << "Wrong number of days! Write a number between 1 and 29.\n";
				this->day = -1;
			}
		}
		else
		{
			if (1 <= day && day <= 28)
			{
				this->day = day;
			}
			else {
				std::cout << "Wrong number of days! Write a number between 1 and 28.\n";
				this->day = -1;
			}
		}
	}
}

int Date::getDay()
{
	return this->day;
}

Date Date::loadDate()
{
	std::cout << "Write year: \n";

	int year;
	std::cin >> year;
	Date::setYear(year);

	std::cout << "Write month: \n";
	int month;
	std::cin >> month;
	setMonth(month);
	while (getMonth() == -1)
	{
		std::cin >> month;
		Date::setMonth(month);
	}

	std::cout << "Write day: \n";
	int day;
	std::cin >> day;
	Date::setDay(day);
	while (getDay() == -1)
	{
		std::cin >> day;
		Date::setDay(day);
	}
	Date date(day, month, year);
	return date;
}

Date Date::loadDateFromFile(std::ifstream& file)
{
	int year;
	int month;
	int day;
	file >> day>>month>>year;
	
	Date date(day, month, year);
	return date;
}

Date::Date()
{
	loadDate();
}

Date::Date(std::ifstream& file)
{
	loadDateFromFile(file);
}

void Date::print()
{
	std::cout << this->getDay() << "." << this->getMonth() << "." << this->getYear()<<std::endl;
}