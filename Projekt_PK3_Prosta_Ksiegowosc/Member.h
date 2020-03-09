#pragma once
#include <iostream>
#include <fstream>

class Member {
private:
	std::string name;
	std::string position;
public:
	std::string getName();
	std::string getPosition();
	bool isSame(Member member);
	bool operator==(Member member);
	static Member loadMember();
	static Member loadMemberFromFile(std::ifstream& file);
	Member(std::string name, std::string position) : name(name), position(position) {};
};