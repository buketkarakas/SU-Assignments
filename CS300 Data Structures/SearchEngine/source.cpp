#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include"strutils.h"
#include "Header.h"
#include <vector>

using namespace std;

int main(){
	LinkedList < string > liststring;

	ifstream input;
	string filename;

	cout << "Enter the file name:";
	cin>>filename;

	input.open(filename.c_str());

	while(input.fail())//check if the file open successfully
	{
		cout<<"Error! Enter the file name again:";
		cin>>filename;
		input.clear();
		input.open(filename.c_str());
	}
	string line;
	int num;
	while(getline(input,line))//reaing inputs from file
	{
		istringstream iss(line);
		string word;
		iss >> word;
		ToLower(word);
		liststring.insert(word);//inserting strings to the list
		iss>>num;

		liststring.docadd(num,word);//adding docnumbers to the list

	}
	int number;
	string query;

	cout <<"Enter number of queries : "; //asking the query number
	cin >>number;
	//if(number==0)
	//{
	//return 0;
	//}
	while(number!=0)//!!ADDED LINE!!
	{

		LinkedList <int> result;
		string finalstring="";//!!ADDED LINE!!
		cout <<"Enter queries : ";//asking the queries

		cin>> query;
		finalstring+=query+" "; //adding to final string
		ToLower(query);
		liststring.gettingdoclist(query,result);//getting doclis to compare

		for(int i=1; i<number;i++)
		{
			cin>>query;
			finalstring+=query+" ";
			ToLower(query);
			liststring.intersect(query,result);//intersecting resul list and query's doclist
		}
		int size=result.size(); //getting the list size
		cout<<finalstring;
		cout<<size<<" ";
		result.printList();//printing result
		cout <<endl<<"Enter number of queries : "; //asking the query number !!ADDED LINE!!
		cin >>number;//!!ADDED LINE!!

	}
	return 0;

}
