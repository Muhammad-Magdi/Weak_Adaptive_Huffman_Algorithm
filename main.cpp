#include <iostream>
#include "Node.h"
#include <algorithm>

using namespace std;

const int M = 26, E = 4, R = 10;
string input, output;
const char NYT = 0;

enum NodeType{INTERNAL = 0, EXTERNAL};

string getSymbolPath(Node*, char);
Node* getNode(Node*, char);
void incrementWeights(Node*);
void split(Node*, char);
string getSymbolCode(char);
void inOrderTraversal(Node*);

Node* root = new Node(EXTERNAL);

int main() {
	root->setSymbol(NYT);

	cin >> input;
	for(char symbol : input){
		if(root->myChildren.count(symbol)){
			output += getSymbolPath(root, symbol);
			Node* cur = getNode(root, symbol);
			incrementWeights(cur);
		}else{
			output += getSymbolPath(root, NYT);
			if(symbol == 'r')	cout << getSymbolPath(root, NYT) << endl;
			output += getSymbolCode(symbol);
			Node* cur = getNode(root, NYT);
			split(cur, symbol);
			incrementWeights(cur->getParent());			//The NYT's Parent
		}
		cout << symbol << "*** \n";
		inOrderTraversal(root);
		cout << "**********************\n";
	}
	cout << output << endl;
	return 0;
}

string getSymbolPath(Node* cur, char symbol){
	if(cur->isLeaf && cur->getSymbol() == symbol)	return "";
	if(cur->getRight()->myChildren.count(symbol) || cur->getRight()->getSymbol() == symbol){
		return "1" + getSymbolPath(cur->getRight(), symbol);
	}else{
		return "0" + getSymbolPath(cur->getLeft(), symbol);
	}
}

Node* getNode(Node* cur, char symbol){
	if(cur->isLeaf && cur->getSymbol() == symbol)	return cur;
	if(cur->getRight()->myChildren.count(symbol) || cur->getRight()->getSymbol() == symbol){
		return getNode(cur->getRight(), symbol);
	}else{
		return getNode(cur->getLeft(), symbol);
	}
}

void incrementWeights(Node* cur){
	cur->incrementWeight();
	if(!cur->isLeaf){
		cur->myChildren.insert(cur->getLeft()->myChildren.begin(), cur->getLeft()->myChildren.end());
		cur->myChildren.insert(cur->getRight()->myChildren.begin(), cur->getRight()->myChildren.end());
	}
	if(cur->getParent() == nullptr)	return;
	if(cur->getParent()->getLeft() == cur && cur->getParent()->getRight()->getWeight() < cur->getWeight()){
		swap(cur->getParent()->getLeft(), cur->getParent()->getRight());
	}
	incrementWeights(cur->getParent());
}

void split(Node* NYT, char symbol){
	Node* newCur = new Node(INTERNAL);
	Node* newSymbol = new Node(EXTERNAL);

	newSymbol->setSymbol(symbol);
	newSymbol->setWeight(1);
	newSymbol->setParent(newCur);

	newCur->setParent(NYT->getParent());
	newCur->setRight(newSymbol);
	newCur->setLeft(NYT);
	newCur->myChildren.insert(symbol);
	newCur->myChildren.insert(0);			//The NYT
	if(NYT->getParent())
		NYT->getParent()->setLeft(newCur);
	NYT->setParent(newCur);
	if(root == NYT)	root = newCur;
}

string getSymbolCode(char symbol){
	int k = symbol-'a'+1;
	int e = E, val = k-1;
	if(k <= 2*R)	++e;
	else	val -= R;
	string ret = "";
	while(val){
		if(val&1)
			ret.push_back('1');
		else
			ret.push_back('0');
		val >>= 1;
	}
	while(ret.length() < e){
		ret.push_back('0');
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void inOrderTraversal(Node* cur){
	if(cur == nullptr) return;
	inOrderTraversal(cur->getLeft());
	cout << cur->getSymbol() << " " << cur->getWeight() << endl;
	inOrderTraversal(cur->getRight());
}
