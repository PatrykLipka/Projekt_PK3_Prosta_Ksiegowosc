#include "Member.h"


std::string Member::getName()
{
	return this->name;
}

std::string Member::getPosition()
{
	return this->position;
}


Member Member::loadMember()
{
	std::cout << "Write name of the member: \n";
	std::string name_written;
	std::cin >> name_written;

	std::cout << "Write position of the member\n";
	std::string position_written;
	std::cin >> position_written;

	Member member(name_written, position_written);
	return member;
}

Member Member::loadMemberFromFile(std::ifstream& file)
{
	std::string name;
	std::string position;
	file >> name >> position;

	Member member(name, position);
	return member;
}

bool Member::isSame(Member member)
{
	if (this->getName().compare(member.getName()) == 0 && this->getPosition().compare(member.getPosition()) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Member::operator==(Member member)
{
	if (this->isSame(member) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}