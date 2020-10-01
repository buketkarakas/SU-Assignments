#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include <iostream>
#include <string>
#include <vector>


using namespace std;



template <class T>

class LinkedList
{
	//creating node for the class
	struct node
	{
		T info; 
		node *next;
		LinkedList<int> list; //document list

		node()
		{
			next=NULL;
		}
	};
public:
	LinkedList();
	~LinkedList();
	void insert(T s);
	void printList();
	void updatingresult(LinkedList<int>&);
	void docadd(int ,string);
	void gettingdoclist(string,LinkedList<int>&);
	void intersect(T,LinkedList<int>&);
	void makelistempty()
	{
		head=NULL;
		
	}
	int size()
	{
		node* p = head;
		int count=0;
		while (p != NULL) 
		{ 
			if(p->info!=NULL)
			{
				++count; 
			}
			p = p->next; 
		}
		return count;
	};
	node* returnhead()
	{
		return head;
	};

private:
	node *head;

};
template <class T>

LinkedList < T>  :: LinkedList(){ //constructor
	head=NULL;
}

template <class T>

LinkedList<T>::~LinkedList()//destructor
{

	node * current = head;
	while(current != NULL)
	{
		node * ptr = current->next;
		current->list.makelistempty();
		delete current;
		current = ptr;
	}

}
template <class T>

void LinkedList < T>:: printList() //printing the linked list
{
	node* ptr = head;
	while (ptr!=NULL)

	{
		if(ptr->info!=NULL) //for the result list if the info is zero it will not print
		{
			cout<<ptr->info<<" " ;
		}
		ptr->list.printList();
		ptr = ptr->next;
	}

}

template <class T>

void LinkedList < T> ::insert(T s){ //insertion to the list

	node *newnode=new node;
	newnode->info=s;
	newnode->next=NULL;

	if (head == NULL || (head)->info > newnode->info) //the empty list and inserting to the beggining case
	{
		newnode->next = head;
		head = newnode;
		return;
	}

	node *current = head;
	bool flag=false;
	while(current->next != NULL && current->next->info <= newnode->info) //inserting into the middle or end case
	{
		if(current->info==newnode->info)
			flag=true;
		current = current->next;
	}
	if(!flag&&current->info!=newnode->info)
	{
		newnode->next = current->next;
		current->next = newnode;
	}
}

template <class T>
void LinkedList < T>:: docadd( int num,string word )
{
	node*temp=head;
	while(temp->info!=word) //getting to the target node of the stringlinkedlist
	{
		temp=temp->next;
	}
	if(temp->list.returnhead()==NULL) //if that stringlinkedlist's intlist is empty
	{
		LinkedList < int >	listint;//create new int list
		temp->list=listint;
		temp->list.insert(num);
	}
	else//otherwise just insert num to the int list
	{
		temp->list.insert(num);
	}
}

template <class T>
void LinkedList<T>:: gettingdoclist(string s,LinkedList<int>&l) //getting the int list of the "s" node of string list
{
	node  *temp=head;

	while(temp!=NULL&&temp->info!=s )
		temp=temp->next;

	if(temp!=NULL)
	{
		l=temp->list;
	}


}

template <class T>

void LinkedList<T>::intersect(T s,LinkedList<int>&result) //intersecting the result list and s string's doc list
{
	node *temp=head;

	while(temp!=NULL&&temp->info!=s )//coming to the s string node
		temp=temp->next;
	if(temp!=NULL)
	{
		LinkedList<int> checking=temp->list; //getting that node's doc list
		result.updatingresult(checking); //sending the doc list and result to intersect
	}
	else
	{
		result.makelistempty();
	}
}




template <class T>
void LinkedList<T>::updatingresult(LinkedList<int>&checking) //intersecting th result and checking list 
{
	bool flag;
	node *ptr=head;
	while(ptr!=NULL) //traverse the result list
	{
		node*ptr2=checking.returnhead();
		flag=false;
		while(ptr2!=NULL)//traverse the checking list
		{
			if(ptr2->info==ptr->info) // if the item in result also exist in checking,means they intersect flag is true
				flag=true;
			ptr2=ptr2->next;
		}
		if(!flag) // if the item in result list is not in checking list make it zero so it will not be printed
		{
			ptr->info=0;

		}

		ptr=ptr->next;
	}
}
#endif
