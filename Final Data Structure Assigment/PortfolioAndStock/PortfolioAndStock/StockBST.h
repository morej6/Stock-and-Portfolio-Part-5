//****************************************************
// File: StockBST.h
//
// Purpose: Contains a Binary Search tree of Stock.
//
// Written By: Juan Moreno
// 
// Compiler: Visual C++ 2015
//****************************************************
#ifndef STOCKBST_H
#define STOCKBST_H
#include "Stock.h"
#include <string>
#include <iostream>
#include <iomanip>

class StockBST {
	//****************************************************
	// Function: Private 
	//
	// Purpose: To hide implementation for the class
	//
	//****************************************************
private:

	//****************************************************
	// Function: Struct 
	//
	// Purpose: To create a node data type for the BST 
	//
	//****************************************************
	struct  Node {
		Stock	info;
		Node*	left;
		Node*	right;
	};

	Node *root;
	int lenght;


	//****************************************************
	// Function: Helper Functions  
	//
	//****************************************************

	//****************************************************************************
	// Function: privateAdd
	//
	// Purpose: Inserts a new Stock into the BST. It creates a node dynamically
	//			and searches where it should be place. (Add them in order base on Stock name)
	//
	// Big O notation : (Log N)
	//****************************************************************************
	void privateAdd(Node*& tree, Stock item);

	//****************************************************************************
	// Function: privateInorder
	//
	// Purpose: Prints the tree in Inorder
	//
	// Big O notation : (N)
	//****************************************************************************
	void privateInorder( Node *tree);

	//****************************************************************************
	// Function: privatePreorder
	//
	// Purpose: Prints the tree in Preorder
	//
	// Big O notation : (N)
	//****************************************************************************
	void privatePreorder(Node *tree);

	//****************************************************************************
	// Function: privatePostorder
	//
	// Purpose: Prints the tree in Postorder
	//
	// Big O notation : (N)
	//****************************************************************************
	void privatePostorder(Node *tree);

	//****************************************************************************
	// Function: privateClear
	//
	// Purpose: Empties the BST 
	//
	// Big O notation : (N)
	//****************************************************************************
	void privateClear(Node *&tree);

	//****************************************************************************
	// Function:  PrintTree
	//
	// Purpose:  outputs BST in Infix order.
	//
	// Big O notation : (N)
	//****************************************************************************
	void PrintTree(Node* tree, std::ostream& out);

	//****************************************************************************
	// Function: CopyTree
	//
	//  Purpose: Used to perform a deep copy from one member variables and copy data
	//			from one variable to another
	//
	// Big O notation : (N)
	//****************************************************************************
	void CopyTree(Node*& copy, const Node* originalTree);

	//****************************************************************************
	// Function: SearchTree
	//
	// Purpose: Searches the tree for a Stock by name. When found it return true if found
	//			false if not found and returns by reference the Stock share number
	//
	// Big O notation : (Log N)
	//****************************************************************************
	bool SearchTree(Node *tree, std::string name, double & share);

public:
	//****************************************************************************
	// Function: Constructor
	//
	// Purpose: Set default Values
	//			 
	// Big O notation : (1)
	//****************************************************************************
	StockBST();

	//****************************************************************************
	// Function: Copy Constructor
	//
	//  Purpose: Used to perform a deep copy from one member variables and copy data
	//			from one variable to another
	//
	// Big O notation : (N)
	//****************************************************************************
	StockBST(const StockBST& rhs);

	//****************************************************************************
	// Function: Destructor
	//
	// Purpose: Free memory
	//
	// Big O notation : (N) 
	//****************************************************************************
	~StockBST();

	//****************************************************************************
	// Function: Clear
	//
	// Purpose: Empties the BST 
	//
	// Big O notation : (N)
	//****************************************************************************
	void Clear();

	//****************************************************************************
	// Function: Size
	//
	// Purpose: Returns the size of the BST (number of node).
	//
	// Big O notation : (1)
	//****************************************************************************
	int Size();

	//****************************************************************************
	// Function: Add
	//
	// Purpose: Inserts a new Stock into the BST. It creates a node dynamically
	//			and searches where it should be place. (Add them in order base on Stock name)
	//
	// Big O notation : (Log N)
	//****************************************************************************
	void Add(Stock s);

	//****************************************************************************
	// Function: Preorder
	//
	// Purpose: Prints the tree in Preorder
	//
	// Big O notation : (N)
	//****************************************************************************
	void Preorder();

	//****************************************************************************
	// Function: Inorder
	//
	// Purpose: Prints the tree in Inorder
	//
	// Big O notation : (N)
	//****************************************************************************
	void Inorder();

	//****************************************************************************
	// Function: Postorder
	//
	// Purpose: Prints the tree in Postorder
	//
	// Big O notation : (N)
	//****************************************************************************
	void Postorder();

	//****************************************************************************
	// Function: GetShares
	//
	// Purpose: Searches the tree for a Stock by name. When found it return true if found
	//			false if not found and returns by reference the Stock share number
	//
	// Big O notation : (Log N)
	//****************************************************************************
	bool GetShares(std::string name, double& shares); 

	//****************************************************************************
	// Function: operator=
	//
	// Purpose: Overoading the assigment operator to set one instance of StockBST
	//          to another.
	//
	// Big O notation : (N)
	//****************************************************************************
	StockBST& operator=(const StockBST& rhs);

	//****************************************************************************
	// Function:  operator<<
	//
	// Purpose: Overloading the ostream operator, outputs BST in Infix order.
	//
	// Big O notation : (N)
	//****************************************************************************
	friend std::ostream & operator<<(std::ostream & os,	 StockBST &ref);
	
};
#endif