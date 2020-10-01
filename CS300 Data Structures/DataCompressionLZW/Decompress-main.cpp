  
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ostream>

using namespace std;

//Buket Karakas,2018
int main()
{
	ofstream output;
	output.open("decompout.txt");
	string arr[4096];
	//Putting ASCII table into the array
	for(int i=0;i<256;i++)
	{
		arr[i]=char(i);
	}
	ifstream input;
	string name;
	cout << "enter a file name:";
	cin >> name;
	input.open(name.c_str());
	//Openning the input file
	while(input.fail())
	{
		input.clear();
		cout << "Wrong name! Enter again:";
		cin>>name;
		input.open(name.c_str());
	}
	//Reading the first number and output it to the file
	int nump,numq;
	input >> numq;
	output << char(numq);
	int key=255;
	//getting inputs from the file
	while(input >> nump)
	{
		if(nump<=key) // if nump is in the dictionary
		{
			key=key+1;//increase key
			arr[key]=arr[numq]+arr[nump].at(0);//assign that key to previous number's string+present number's strings first char
			output<<arr[nump];//output the present nummber
		}
		else
		{
			key=key+1;//increase the key
			arr[key]=arr[numq]+arr[numq].at(0);//assign that key to previous number+previous numbers first char
			output << arr[key];//output the key's string
		}
		numq=nump;//assign numq to nump so we can trace the previous number
	}



	return 0;
}
