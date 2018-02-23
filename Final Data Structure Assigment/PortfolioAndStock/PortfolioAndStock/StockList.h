
//****************************************************
// File: StockList.h
//
// Purpose: Contains an list of Stock.
//
// Written By: Juan Moreno
// 
// Compiler: Visual C++ 2015
//****************************************************
#ifndef STOCKLIST_H
#define STOCKLIST_H
#include <string>
#include "Stock.h"
#include<iostream>

class StockList
{


	//****************************************************
	// Function: Private 
	//
	// Purpose: To hide implementation for the class
	//
	//
	//****************************************************
private:
	//****************************************************
	// Function: Struct 
	//
	// Purpose: To create a node data type for the link list
	//
	//
	//****************************************************
	struct node
	{
		Stock data;
		node* next;
	};
	int length;
	node *listData; 

public:
	//****************************************************************************
	// Function: Constructor
	//
	// Purpose: Set default Values
	//			 
	// Big O notation : (1)
	//****************************************************************************
	StockList();

	//****************************************************************************
	// Function: Copy Constructor
	//
	//  Purpose: Used to perform a deep copy on variables to copy data
	//			from one variable to aother
	//
	// Big O notation : (1)
	//****************************************************************************
	StockList(const StockList& otherList);

	//****************************************************************************
	// Function: Destructor
	//
	// Purpose: Free memory
	//
	// Big O notation : (N) 
	//****************************************************************************
	~StockList();

	//****************************************************************************
	// Function: operator=
	//
	// Purpose: Overoading the assigment operator to set one instance of StockList
	//          to another.
	//
	// Big O notation : (N)
	//****************************************************************************
	StockList & operator=(StockList& rhs);

	//****************************************************************************
	// Function: Clear
	//
	// Purpose: Empties the StockList variable
	//
	// Big O notation : (N)
	//****************************************************************************
	void Clear();

	//****************************************************************************
	// Function: Lenght
	//
	// Purpose: Returns length value
	//
	// Big O notation : (1)
	//****************************************************************************
	int Length() const;

	//****************************************************************************
	// Function: Add
	//
	// Purpose: Adds a Stock variable to the StockList variable
	//
	// Big O notation : (1)
	//****************************************************************************
	void Add(const Stock s);

	//****************************************************************************
	// Function: Add
	//
	// Purpose: Add takes in a StockList variable and Adds it to the list.
	//
	// Big O notation : (N)
	//****************************************************************************
	void Add(const StockList& otherList);

	//****************************************************************************
	// Function: FindByName
	//
	// Purpose:	Searches the list for the given name, and returns the name info.
	//
	// Big O notation : (N)
	//****************************************************************************
	bool FindByName(std::string name, Stock &result) const;

	//****************************************************************************
	// Function: Delete
	//
	// Purpose: Searching the list and deletes the first name that matches.
	//
	// Big O notation : (N)
	//****************************************************************************
	void Delete(std::string name);

	//****************************************************************************
	// Function:  operator<<
	//
	// Purpose: Overloading the ostream operator output data.
	//
	// Big O notation : (N)
	//****************************************************************************
	friend std::ostream & operator<<(std::ostream & os, StockList &ref);

	//****************************************************************************
	// Function:  operator>>
	//
	// Purpose: Overloading the istream operator to insert data to list variable.
	//
	// Big O notation : (N)
	//****************************************************************************
	friend std::istream & operator>> (std::istream& is, StockList& rhs);

};

#endif 