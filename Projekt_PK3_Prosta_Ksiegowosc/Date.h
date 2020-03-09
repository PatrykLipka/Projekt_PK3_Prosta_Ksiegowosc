#pragma once
#include <iostream>
#include <fstream>

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(std::ifstream&);
	Date(int day, int month, int year) : day(day), month(month), year(year) {};
	bool operator <=(Date);
	bool operator >=(Date);
	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	void setDay(int day);
	int getDay();
	Date loadDate();
	Date loadDateFromFile(std::ifstream&);
	bool isLeapYear();
	void print();
};