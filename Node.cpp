//
// Created by muhammad on 4/23/18.
//

#include "Node.h"


Node ::Node(bool pIsLeaf) {
	isLeaf = pIsLeaf;
	symbol = 0;
}

void Node ::setLeft(Node* pLeft) {
	left = pLeft;
}

void Node ::setRight(Node* pRight) {
	right = pRight;
}

void Node ::setParent(Node * pParent) {
	parent = pParent;
}

void Node::setWeight(int pWeight) {
	weight = pWeight;
}

void Node ::setNumber(int pNumber) {
	number = pNumber;
}

void Node ::setSymbol(char pSymbol) {
	symbol = pSymbol;
}

void Node ::incrementWeight() {
	++weight;
}

Node*& Node::getLeft() {
	return left;
}

Node*& Node ::getRight() {
	return right;
}

Node*& Node ::getParent() {
	return parent;
}

int Node ::getWeight() {
	return weight;
}

int Node ::getNumber() {
	return number;
}

char Node ::getSymbol() {
	return symbol;
}