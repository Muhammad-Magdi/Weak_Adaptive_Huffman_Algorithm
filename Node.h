//
// Created by muhammad on 4/23/18.
//

#ifndef AHTA3BAN_NODE_H
#define AHTA3BAN_NODE_H

#include <set>

using namespace std;

class Node {
private:
	int weight;
	int number;
	char symbol;
	Node* left, * right, * parent;
public:
	Node(bool);
	void setWeight(int);
	void setNumber(int);
	void setLeft(Node*);
	void setRight(Node*);
	void setParent(Node*);
	void setSymbol(char);
	void incrementWeight();
	int getWeight();
	int getNumber();
	Node*& getLeft();
	Node*& getRight();
	Node*& getParent();
	char getSymbol();
	bool isLeaf;
	set<char> myChildren;
};


#endif //AHTA3BAN_NODE_H
