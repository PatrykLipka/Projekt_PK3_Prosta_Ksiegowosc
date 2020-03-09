#pragma once
#include "MemberNode.h"

class MemberList {
private:
	MemberNode* pHead;

public:
	MemberList();
	~MemberList();
	MemberNode* getHead();
	void setHead(MemberNode*);
	void addNode();
	void addNodeFromFile(std::ifstream&);
	void addNode(Member, MemberList&);
	bool isInList(Member);
	void print();

	void printToFile();
	void loadFromFile();
};
