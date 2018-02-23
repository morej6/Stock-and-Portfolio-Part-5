
//****************************************************
// File: StockQueue.h
//
// Purpose: Contains a Stack of Stock.
//
// Written By: Juan Moreno
// 
// Compiler: Visual C++ 2015
//****************************************************
#ifndef STOCKSTACK_H
#define STOCKSTACK_H
#include <string>
#include "Stock.h"
#include<iostream>

class StockStack {

	//****************************************************
	// Function: Private 
	//
	// Purpose: To hide implementation for the class
	//
	//
	//****************************************************
private:

	int STOCK_ARRAY = 10;
	int top;
	Stock *m_array;

public:
	//****************************************************************************
	// Function: Constructor
	//
	// Purpose: Set default Values
	//			 
	// Big O notation : (N)
	//****************************************************************************
	StockStack();

	//****************************************************************************
	// Function: Constructor with parameters
	//
	// Purpose: Takes an int value and sets that as the new size for the array.
	//			 
	// Big O notation : (N)
	//****************************************************************************
	StockStack(int max);


	//****************************************************************************
	// Function: Copy Constructor
	//
	//  Purpose: Used to perform a deep copy on member variables and copy data
	//			from one variable to another
	//
	// Big O notation : (N)
	//****************************************************************************
	StockStack(const StockStack& rhs); 

	//****************************************************************************
	// Function: Destructor
	//
	// Purpose: Free memory
	//
	// Big O notation : (1) 
	//****************************************************************************
	~StockStack();


	//****************************************************************************
	// Function: Clear
	//
	// Purpose: Empties the Stack 
	//
	// Big O notation : (1)
	//****************************************************************************
	void Clear();

	//****************************************************************************
	// Function: Size
	//
	// Purpose: Returns the size of the Stack (number of elements).
	//
	// Big O notation : (1)
	//****************************************************************************
	int Size();

	//****************************************************************************
	// Function: MaxStorage
	//
	// Purpose: Returns the Max size the Stack can be.
	//
	// Big O notation : (1)
	//****************************************************************************
	int MaxStorage();

	//****************************************************************************
	// Function: Push
	//
	// Purpose: Inserts a new Stock into the Stack.
	//
	// Big O notation : (1)
	//****************************************************************************
	bool Push(Stock s);

	//****************************************************************************
	// Function: Pop
	//
	// Purpose: Deletes a Stock from the Stack.
	//
	// Big O notation : (1)
	//****************************************************************************
	bool Pop();

	//****************************************************************************
	// Function: Top
	//
	// Purpose: Returns the item at the top of the Stack (last item push)
	//
	// Big O notation : (1)
	//****************************************************************************
	bool Top(Stock &returnedStock);

	//****************************************************************************
	// Function: operator=
	//
	// Purpose: Overoading the assigment operator to set one instance of StockStack
	//          to another.
	//
	// Big O notation : (N)
	//****************************************************************************
	StockStack & operator=(StockStack& rhs);


	//****************************************************************************
	// Function:  operator<<
	//
	// Purpose: Overloading the ostream operator output data.
	//
	// Big O notation : (N)
	//****************************************************************************
	friend std::ostream & operator<<(std::ostream & os, StockStack &ref);
	




};
#endif