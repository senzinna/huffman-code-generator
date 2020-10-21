// Scott Enzinna

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "Header.h"
using namespace std;

int main()
{

	// Int var's
	int count = 0;
	int x = 0;
	int y = 0;

	// Read from file named file.txt
	ifstream infile;
	infile.open("message.txt");
	char a;
	vector<int> temp(150);
	while (!infile.eof())
	{
		a = infile.get();
		temp[a]++;
		count++;
	}
	infile.close();

	// Places the vaues in BST
	for (int x = 0; x < temp.size(); x++)
	{
		if (temp[x] != 0)
		{
			node T;
			T.frequency = (double)temp[x] / ((double)count - 1.0);
			T.content = x;
			T.leftChild = NULL;
			T.rightChild = NULL;
			tempVector.push_back(T);
		}
	}

	// Buliding the tree by using comparisons
	node root = buildTree();
	getCode(&root, "");
	bool finished = false;
	while (!finished)
	{
		finished = true;
		for (int B = 0; B < sortedVector.size(); ++B)
		{
			if (sortedVector[B].frequency < sortedVector[B + 1].frequency)
			{
				node hold = sortedVector[B];
				sortedVector[B] = sortedVector[B + 1];
				sortedVector[B + 1] = hold;
				finished = false;
			}
		}
	}

	// Make the text file named output and save the data to the file
	ofstream outfile;
	outfile.open("messageCode.txt");

	outfile << "Frequency\tCode\t\tCharacter\n"
			<< endl;
	for (int B = 0; B < sortedVector.size(); B++)
	{
		//outfile << endl;
		outfile << fixed << setprecision(3) << sortedVector[B].frequency << "\t\t";
		outfile << sortedVector[B].code << "\t\t";

		if (sortedVector[B].content == ' ')
			outfile << "Space" << endl;
		else if (sortedVector[B].content == '\n')
			outfile << "Newline" << endl;
		else
			outfile << sortedVector[B].content << endl;
	}
	outfile.close();

	// Done
	cout << "Scott Enzinna\n"
		 << "File created -> output.txt\n\n"
		 << endl;

	// Prints on screen
	cout << "Frequency\tCode\t\tCharacter\n"
		 << endl;
	for (int B = 0; B < sortedVector.size(); B++)
	{
		//outfile << endl;
		cout << fixed << setprecision(3) << sortedVector[B].frequency << "\t\t";
		cout << sortedVector[B].code << "\t\t";

		if (sortedVector[B].content == ' ')
			cout << "Space" << endl;
		else if (sortedVector[B].content == '\n')
			cout << "Newline" << endl;
		else
			cout << sortedVector[B].content << endl;
	}
	return 0;
}