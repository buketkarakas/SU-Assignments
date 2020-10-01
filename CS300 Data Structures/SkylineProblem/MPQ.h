#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct building //building struct for the heap
{
	int value; // height of the building
	int label; //order of the building
	building operator=(const building & i){ // overloading for assignment operator
		this->label= i.label;
		this->value= i.value;

		return *this;
	}
};

class MPQ //heap class
{
public:
	MPQ(int capacity); //constructor
	~MPQ(); //destructor
	bool isEmpty();
	int getMax();
	void insert(int& label,int& value);
	int remove(int & label);
private:
	building *arr; //heap
	int currentSize; //currentsize of the heap

	void buildHeap(); 
	void percolateDown( int hole); 

	int *index; //index array

};

MPQ::MPQ(int capacity) 
{
	arr = new  building[capacity]; //creating heap 
	index= new int[capacity]; //creating index array
	currentSize=0;

	for(int i=0;i<capacity;i++) //initializing 0 to whole array indexes
	{
		arr[i].value=0;
		arr[i].label=0;
	}
}

MPQ::~MPQ()
{
	//destructor of the heap and index array

	delete [] index;
	delete [] arr;
}

void MPQ::insert(  int&label,int&value ) //insertþng building to the maxheap
{
	// Percolate up
	// Note that instead of swapping we move the hole up
	int hole = ++currentSize;
	for( ; hole > 1 && value > arr[ hole / 2 ].value; hole /= 2 )
	{
		arr[ hole ]= arr[ hole / 2 ];
		index[arr[ hole ].label]=hole; //putting the correct number to the index array

	}
	arr[ hole ].label = label;
	arr[ hole ].value = value;
	index[arr[ hole ].label]=hole; //putting the correct number to the index array
}

bool MPQ :: isEmpty()
{
	return arr[1].value==0; // if the first element is zero than the heap is empty
}

int MPQ :: getMax()
{
	if(!isEmpty()) //if the heap is not empty than the first element is the max
		return arr[1].value;
	else
		return 0; // if it is empty return 0 
}

int  MPQ :: remove(int & label)
{


	if(index[label]==currentSize) //if the index is current size directly delete the building 
	{
		arr[index[label]].label=0;
		arr[index[label]].value=0;
		index[label]=0;
		currentSize--; //decrease the current size and return
		return 0;
	}
	//if it is not the last building
	building temp=arr[index[label]]; //create temp and hold the building to be deleted
	arr[index[label]]=arr[currentSize--]; //make the deleted element's spot the last element
	index[arr[ currentSize+1 ].label]=index[label]; //correct the indexes of the elements in the index list
	percolateDown(index[label]); //percolate down the element that you put to the deleted element's spot
	index[label]=0; //make index of the deleted item 0
	return temp.value;//return the deleted buildings value



}
void MPQ::percolateDown( int hole )
{
	int child;
	building tmp = arr[ hole ]; // tmp is the item that will 
	// be percolated down

	for( ; hole * 2 <= currentSize; hole = child )
	{
		child = hole * 2;
		if( child != currentSize && arr[ child + 1 ].value < arr[ child ].value )
			child++;  // child is the minimum of the children
		if( arr[ child ].value < tmp.value )
		{
			arr[ hole ] = arr[ child ]; // swap hole and min child
			index[arr[hole].label]=hole;
		}
		else
			break;
	}
	arr[ hole ] = tmp; // place tmp in its final position
	index[arr[hole].label]=hole;
}

