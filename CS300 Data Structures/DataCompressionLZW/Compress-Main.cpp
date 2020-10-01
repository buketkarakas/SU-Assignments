#include <iostream>
#include <string>
#include "Header.h"
#include <sstream>
#include <fstream>
#include <ostream>

using namespace std;

void compress(string & s,BinarySearchTree&dict) //compress function
{
	ofstream output;
	output.open("compout.txt"); //creating a output file
	int i=0; //index of string
	int key=255; //key
	int k=1; //how many char to take from given index
	while(i<s.length()) //until i is over s
	{

		if(!dict.isExist(s.substr(i,k+1))) //if k+1 length substring from i th index is not in dictionary
		{
			if(k==1) //if k is 1
			{
				key+=1; //increase key 1
				dict.insert(key,s.substr(i,k+1)); //insert the k+1 length substr from i th index with given key
				output << int(s.at(i))<<" "; //output the ascii value of index i th char of string
				i=i+k; //shift i by k 
			}
			else//if k is larger than 1
			{
				key+=1; //increase key
				dict.insert(key,s.substr(i,k+1)); // insert the k+1 length substr from i th index with given key
				output << dict.printkey(s.substr(i,k))<<" "; // print the k length substr from i th index 
				i=i+k;//shift i by k

			}
			k=1; //make k 1 again

		}
		else //if it is  in dict
		{
			k++;//increase k
			if(i+k==s.length())//if it is the last substr of string
			{
				output << dict.printkey(s.substr(i,k))<<" ";
				output.close();
				break;
			}

		}
	}

	output.close();

}

int main()
{
	ifstream input;
	string name;
	cout <<"Enter file name:";
	cin >> name;

	input.open(name.c_str());


	while(input.fail()) //check if the file is opened
	{
		input.clear();
		cout <<"Wrong name!";
		cout<<endl<<"Enter file name again:";
		cin >> name;
		input.open(name.c_str());

	}
	BinarySearchTree dict; //create a binary tree

	char ch;
	string file;
	while (input.get(ch)) //get char by char from file
	{		
		file+=ch;//put them into a string
	}
	compress(file,dict); //compress file 

	return 0;
}
