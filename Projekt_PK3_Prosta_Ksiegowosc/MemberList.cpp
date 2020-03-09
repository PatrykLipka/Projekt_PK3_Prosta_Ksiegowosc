#include "MemberList.h"

MemberList::MemberList()
{
	this->pHead = nullptr;
}

MemberList::~MemberList()
{
	while (pHead)
	{
		MemberNode* temp = pHead->getNext();
		delete pHead;
		pHead = temp;
	}
}

MemberNode* MemberList::getHead()
{
	return this->pHead;
}

bool MemberList::isInList(Member member)
{
	MemberNode* temp = pHead;
	while (temp)
	{
		if (temp->getNode()==member)
		{
			return true;
		}
		temp = temp->getNext();
	}
	return false;
}

void MemberList::addNode()
{
	if (!pHead)
	{
		Member member = Member::loadMember();
		MemberNode* Node = new MemberNode(member);
		pHead = Node;
	}
	else {
		Member member = Member::loadMember();
		if (!isInList(member))
		{
			MemberNode* Node = new MemberNode(member, pHead);
			pHead = Node;
		}
		else {
			std::cout << "Member already on the list!\n";
		}
	}
}



void MemberList::setHead(MemberNode* Node)
{
	this->pHead = Node;
}


void MemberList::addNode(Member member, MemberList& list)
{
	if (!list.getHead())
	{
		MemberNode* Node = new MemberNode(member);
		list.setHead(Node);
	}
	else 
	{
		MemberNode* Node = new MemberNode(member, pHead);
		list.setHead(Node);
	}
}


void MemberList::print()
{
	MemberNode* temp;
	if (pHead)
	{
		temp = pHead;
	}
	else {
		std::cout << "Nothing to print!\n";
		return;
	}
	while (temp)
	{
		std::cout << "Name and Position: \n   " << temp->getNode().getName() << " " << temp->getNode().getPosition() << std::endl<< std::endl;
		temp = temp->getNext();
	}
}

void MemberList::printToFile()
{
	std::ofstream file;
	file.open("MemberList.txt");
	MemberNode* temp;
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
			file << temp->getNode().getName() << " " << temp->getNode().getPosition() << std::endl;
		}
		else
		{
			file << temp->getNode().getName() << " " << temp->getNode().getPosition();
		}
		temp = temp->getNext();
	}
	file.close();
}


void MemberList::addNodeFromFile(std::ifstream &file)
{
	if (!pHead)
	{
		Member member = Member::loadMemberFromFile(file);
		MemberNode* Node = new MemberNode(member);
		pHead = Node;
	}
	else {
		Member member = Member::loadMemberFromFile(file);
		if (!isInList(member))
		{
			MemberNode* Node = new MemberNode(member, pHead);
			pHead = Node;
		}
	}
}

void MemberList::loadFromFile()
{
	std::ifstream file;
	file.open("MemberList.txt");
	if(file.good())
	{
		while (!file.eof())
		{
			addNodeFromFile(file);
		}
	}
	file.close();
}