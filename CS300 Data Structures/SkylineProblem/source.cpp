#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "MPQ.h"
#include <algorithm>
using namespace std;



enum dir{L,R,null};//direction for the edges

struct info // info about the building struct
{
	int no; //reading order of the building
	int height;//height of the building
	int coord;//what is the current coordinate
	dir direction;//which direction is the edge

	info() //default constructor of the struct to initiliaze 0
	{
		no=0;
		height=0;
		coord=0;
		direction=null;
	}
	info(int n,int h,int c, dir d) //constructor
	{
		no=n;
		height=h;
		coord=c;
		direction=d;
	}
};

bool sortCoords(const info a, const info b){ //for sorting acording to coordinates
	return(a.coord < b.coord);
}



int main()
{
	ifstream input;
	string name;
	cout <<"Enter File Name:";
	cin >> name;

	input.open(name.c_str());

	while(input.fail())
	{
		cout <<"Wrong name! Enter File Name:";
		cin >> name;
		input.open(name.c_str());

	}
	int num;

	input >> num; //taking the first number 
	int height,l_coord,r_coord;

	vector <info> skyline(2*num); //creating a vector size of twice of the buildings since each building will have 2 edges
	int count=0; //count for determining the number of the building
	int index=0; //index for putting the building to the vector

	MPQ maxheight(num+2); //creating a heap to keep building while we are reading them from the vector
	
	for(;num>0;num--) // reading from the input
	{
		count++;
		input >> l_coord;
		input >> height;
		input >> r_coord;

		info tmp(count,height,l_coord,L); //left edge
		info tmp2(count,height,r_coord,R);//right edge
		skyline[index]=tmp; //putting edges to the vector
		skyline[++index]=tmp2;
		index++;
	}

	std::sort(skyline.begin(), skyline.end(), sortCoords);//sorting the vector skyline
	int max=INT_MIN;
	if(skyline[0].coord!=0) // if the index 0 is empty cout the output
	{
		cout <<"0"<<" "<<"0"<<endl;
	}

	
	bool print=true; //for the edges that are in the same coordinate
	
	for(int i=0;i<skyline.size();i++)
	{
		if(skyline[i].direction==L) // if the direction is left 

		{
			if(i+1!=skyline.size()&& skyline[i].coord==skyline[i+1].coord) // if the next edge's coordinate is same with yours do not print
				print=false;// make print false
			else//otherwise print the ourput
				print=true;



			maxheight.insert(skyline[i].no,skyline[i].height);//insert the building to the maxheap
		}
		else
		{
			if(i+1!=skyline.size()&& skyline[i].coord==skyline[i+1].coord) // if the next edge's coordinate is same with yours do not print
				print=false;
			else//otherwise
				print=true;//print
			maxheight.remove(skyline[i].no);//remove the building from the maxheap

			if(max==skyline[i].height) // if maximum is the one that we are deleting from the max heap make max variable=0
				max=0;
		}

		if(print)// if print is true
		{
			int k=maxheight.getMax(); // get the maximum of the heap
			if(k==0)//if it is zero make maximum 0 and and output 
			{
				max=0;
				cout<< skyline[i].coord<<" "<<"0"<<endl;
			}
			else if(k>max)// if the new maxiumum of the heap is bigger than the max make it max and output it
			{

				max=k;
				cout<< skyline[i].coord<<" "<<max<<endl;
			}
		}


	}













	return 0;
}
