
//****************************************************
// File: StockQueue.h
//
// Purpose: Contains a Queue of Stock.
//
// Written By: Juan Moreno
// 
// Compiler: Visual C++ 2015
//****************************************************
#ifndef STOCKQUEUE_H
#define STOCKQUEUE_H
#include "Stock.h"
#include <string>
#include <iostream>
class StockQueue {

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
	// Purpose: To create a node data type for the Queue list
	//
	//
	//****************************************************
	struct QueNode
	{
		Stock data;
		QueNode *next;

	};
	int size;
	QueNode *front;
	QueNode *rear;

public:
	//****************************************************************************
	// Function: Constructor
	//
	// Purpose: Set default Values
	//			 
	// Big O notation : (1)
	//****************************************************************************
	StockQueue(); //done

	//****************************************************************************
	// Function: Copy Constructor
	//
	//  Purpose: Used to perform a deep copy on member variables and copy data
	//			from one variable to another
	//
	// Big O notation : (N)
	//****************************************************************************
	StockQueue(const StockQueue& rhs); //done

	
	//****************************************************************************
	// Function: Destructor
	//
	// Purpose: Free memory
	//
	// Big O notation : (N) 
	//****************************************************************************
	~StockQueue(); //done

	//****************************************************************************
	// Function: Clear
	//
	// Purpose: Empties the Queue 
	//
	// Big O notation : (N)
	//****************************************************************************
	void Clear();//done

	//****************************************************************************
	// Function: Size
	//
	// Purpose: Returns the size of the Queue (number of elements).
	//
	// Big O notation : (1)
	//****************************************************************************
	int Size(); // works

	//****************************************************************************
	// Function: Enqueue
	//
	// Purpose: Inserts a new Stock into the Queue list.
	//
	// Big O notation : (1)
	//****************************************************************************
	void Enqueue(Stock s);//done

	//****************************************************************************
	// Function: Dequeue
	//
	// Purpose: Deletes a Stock from the Queue list.
	//
	// Big O notation : (1)
	//****************************************************************************
	bool Dequeue(Stock& returnedStock); //done

	//****************************************************************************
	// Function: operator=
	//
	// Purpose: Overoading the assigment operator to set one instance of StockQueue
	//          to another.
	//
	// Big O notation : (N)
	//****************************************************************************
	StockQueue & operator=(const StockQueue& rhs); //works

	//****************************************************************************
	// Function:  operator<<
	//
	// Purpose: Overloading the ostream operator output data.
	//
	// Big O notation : (N)
	//****************************************************************************
	friend std::ostream & operator<<(std::ostream & os, StockQueue &ref); //works

};
#endif