#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// Make node Struct
struct node
{
	node *leftChild;
	node *rightChild;
	double frequency;
	char content;
	string code;
};

// Make vectors
vector<node> tempVector;
vector<node> sortedVector;

// Function call to getlow()
node getLow()
{
	double temp = 1.1;
	vector<node>::iterator i1, pos;
	for (i1 = tempVector.begin(); i1 != tempVector.end(); i1++)
	{
		if (temp > (*i1).frequency)
		{
			pos = i1;
			temp = (*i1).frequency;
		}
	}
	node tempNode = (*pos);
	tempVector.erase(pos);
	return tempNode;
}

// Function call to buildTree
node buildTree()
{
	while (tempVector.size() != 1)
	{
		node *tempNode = new node;
		node *tempNode1 = new node;
		node *tempNode2 = new node;
		*tempNode1 = getLow();
		*tempNode2 = getLow();
		tempNode->leftChild = tempNode1;
		tempNode->rightChild = tempNode2;
		tempNode->frequency = tempNode1->frequency + tempNode2->frequency;
		tempVector.push_back(*tempNode);
	}
	return tempVector[0];
}

// Function call to getCode
void getCode(node *temproot, string s)
{
	node *root1 = new node;
	root1 = temproot;
	root1->code = s;
	if (root1 == NULL)
	{
		cout << "error" << endl;
	}
	else if (root1->leftChild == NULL && root1->rightChild == NULL)
	{
		sortedVector.push_back(*root1);
	}
	else
	{
		root1->leftChild->code = s.append("0");
		s.erase(s.end() - 1);
		root1->rightChild->code = s.append("1");
		s.erase(s.end() - 1);
		getCode(root1->leftChild, s.append("0"));
		s.erase(s.end() - 1);
		getCode(root1->rightChild, s.append("1"));
		s.erase(s.end() - 1);
	}
}
