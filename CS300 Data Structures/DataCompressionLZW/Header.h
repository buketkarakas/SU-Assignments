#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H
#include <iostream>
#include <string>

using namespace std;

struct TreeNode { // creating a tree node with key and message 
	int   key;
	string msg;
	TreeNode  * leftchild;
	TreeNode  * rightchild;

	TreeNode::TreeNode()
	{
		leftchild=NULL;
		rightchild=NULL;
	}
};

class BinarySearchTree 
{
public:
	BinarySearchTree(); //constructor

	~BinarySearchTree( ); // destructor


	bool isExist( const string & n) ; //controlling if a string exist in a tree
	int printkey(const string & n ) ; //printing the key of a string

	void makeEmpty( ); //making empty 
	void insert( const int & x,const string & s ); //inserting a key and message to the tree


private:
	TreeNode *root;
	void insert( const int & x,const string & s,TreeNode*&n ) //private insert function
	{
		//inserting nodes according to their messages
		if( n == NULL )
		{//  create a new node at the right place
			n = new TreeNode();
			n->key=x;
			n->msg=s;
		}
		else if( s < n->msg )
			insert( x,s, n->leftchild );  // insert at the left or 
		else if( n->msg < s )
			insert(x, s, n->rightchild );  // right subtree
		else
			;  // Duplicate; do nothing
	}
	void makeEmpty(TreeNode*&t) //make empty private
	{
		if( t != NULL )
		{
			makeEmpty( t->leftchild );//making empty all left children
			makeEmpty( t->rightchild );//making empty all right children
			delete t;
		}
		t = NULL;

	}

};

BinarySearchTree::BinarySearchTree()//constructor
{
	root=NULL;
}

BinarySearchTree::~BinarySearchTree()//destructor
{
	makeEmpty(root); //calling make empty function
}

void BinarySearchTree::insert( const int & x, const string  & s )  //insert public
{
	insert(x,s,root); //sending the coe and message and root to the private 
}

void  BinarySearchTree::makeEmpty( ) //make empty public
{
	makeEmpty( root );
}

bool BinarySearchTree:: isExist( const string  & x )  //controlling if a string is exist
{
	TreeNode*t=root;
	while( t != NULL ){
		if( x < t->msg )
			t = t->leftchild;
		else if( t->msg < x )
			t = t->rightchild;
		else
			return true;    // Match
	}
	return false;          // No match
}

int BinarySearchTree:: printkey(const string & x )  //printing the key of the given string
{
	TreeNode*t=root;
	while( t != NULL ){
		if( x < t->msg )
			t = t->leftchild;
		else if( t->msg < x )
			t = t->rightchild;
		else
			return t->key;    // Match
	}
}


#endif



