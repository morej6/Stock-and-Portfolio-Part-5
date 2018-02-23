
//****************************************************
// File: StockQueue.h
//
// Purpose: To call Lib and run code
//
// Written By: Juan Moreno
// 
// Compiler: Visual C++ 2015
//****************************************************
#include <iostream>
#include "Portfolio.h"
#include "Stock.h"
#include "StockList.h"
#include "StockStack.h"
#include "StockQueue.h"
#include "StockBST.h"
#include <fstream>
using namespace std;

//****************************************************
// Function: Main
//
// Purpose: To call program
//
// Update Information
// ------------------
// 
// Name: Juan Moreno	
// Date: 10/28/2017
// Description: New functions were called in order 
// to test them
//
//*******************************************************

int main()
{
	Stock B;
	B.SetName("B");
	B.SetPrice(34.5);
	B.SetShare(54);
	Stock C;
	C.SetName("C");
	C.SetPrice(98.99);
	C.SetShare(67);
	Stock A;
	A.SetName("A");
	A.SetPrice(99.99);
	A.SetShare(3);
	Stock E;
	E.SetName("E");
	E.SetPrice(99.99);
	E.SetShare(14);
	Stock G;
	G.SetName("G");
	G.SetPrice(99.99);
	G.SetShare(12);

	StockBST bst;
	//Calling add to insert stocks into the tree
	bst.Add(C); 
	bst.Add(G); 
	bst.Add(A);
	bst.Add(E);
	bst.Add(B);
	cout << "****************************************************" << endl;
	cout << "Inorder :" << endl;
	bst.Inorder();
	cout << "****************************************************" << endl;
	cout << "Preorder :" << endl;
	bst.Preorder();
	cout << "****************************************************" << endl;
	cout << "Postorder :" << endl;
	bst.Postorder();
	cout << "****************************************************" << endl;
	cout << "Tree Size :" << endl;
	cout<<bst.Size()<<endl;
	cout << "****************************************************" << endl;
	cout << "Using = oeprator and printing tree :" << endl;
	StockBST bst2;
	bst2 = bst;
	StockBST bst3 = bst2; //calling copy constructor.
	cout << bst3 << endl;
	cout << "****************************************************" << endl;
	cout << "Calling Getshare for G :" << endl;
	double teemo = 0;
	bst3.GetShares("G", teemo);
	cout << teemo << endl;
	//Calling clear for all BST variables
	bst3.Clear();
	bst2.Clear();
	bst.Clear();
	cout << "****************************************************" << endl;
	cout << "Calling Clear on variables there should be no output :" << endl;
	cout << bst << endl;
	cout << bst2 << endl;
	cout << bst3 << endl;


	/*
	cout << "****************************************************" << endl;
	cout << "Testing All Stack functions" << endl;
	//Calling constroctor to set Max array size to 15 from 10.

	StockStack Stack(15); //Setting a new Array size to 15 from 10
	cout << "****************************************************" << endl;
	cout << "Calling MaxStorage" << endl;
	cout << Stack.MaxStorage() << endl; //Checking what the max size the stack can be.
	cout << "****************************************************" << endl;
	//Push is call to insert the following stocks
	Stack.Push(C);
	Stack.Push(A);
	Stack.Push(B);
	
	cout << "Calling Push" << endl;
	cout << "****************************************************" << endl;
	cout << Stack << endl; //Printing what the Stack has.
	cout << "****************************************************" << endl;
	cout << "Calling Pop" << endl;
	cout << "****************************************************" << endl;
	Stack.Pop(); //Deleting one of the Stocks in the Stack
	cout << Stack << endl;
	cout << "****************************************************" << endl;
	cout << "Calling Top" << endl;
	cout << "****************************************************" << endl;
	Stock result;
	Stack.Top(result); //Checking the current Stock, which sits at the top of the stack.
	cout << result << endl;
	cout << "****************************************************" << endl;
	cout << "Calling =" << endl;
	cout << "****************************************************" << endl;
	StockStack copy;
	copy = Stack; //Testing the = operator
	cout << copy << endl; 
	cout << "****************************************************" << endl;
	cout << "Calling Size" << endl;
	cout << "****************************************************" << endl;
	cout << copy.Size() << endl; //Checking the size of the Stack.
	cout << "****************************************************" << endl;
	cout << "Calling Copy constructor" << endl;
	cout << "****************************************************" << endl;
	StockStack Stack2 = Stack; //Calling Copy constructor
	cout << Stack2 << endl;
	Stack2.Clear(); //Calling Clear to erase all data
	Stack.Clear(); //caling clear
	StockQueue Queue;
	cout << "****************************************************" << endl;
	cout << "Testing All Queue functions" << endl;
	cout << "****************************************************" << endl;
	cout << "Calling Enqueue" << endl;
	cout << "****************************************************" << endl;
	//Inserting into the Queue
	Queue.Enqueue(C);
	Queue.Enqueue(B);
	Queue.Enqueue(A);
	cout << Queue << endl; //Printing whats in the queue
	cout << "****************************************************" << endl;
	cout << "Calling Dequeue" << endl;
	cout << "****************************************************" << endl;
	Stock queresult;
	Queue.Dequeue(queresult); //Deleting one item of the Queue
	cout << Queue << endl;
	cout << "This is what was Dequeue : " << endl;
	cout << queresult << endl;
	cout << "****************************************************" << endl;
	cout << "Calling Size" << endl;
	cout << "****************************************************" << endl;
	cout << Queue.Size() << endl; //Calling size and it returns actual values and not the default values from the constructor.
	cout << "****************************************************" << endl;
	cout << "Calling Copy constrcutor" << endl;
	cout << "****************************************************" << endl;
	StockQueue secondQue = Queue; //Copy constructor along with = operator is called.
	cout << secondQue << endl;
	//caling clear on both variables and deleting everything.
	secondQue.Clear();
	Queue.Clear();
	/*
	

	/*
	Stock s;  //Constructor is called.

			  //SET/GET Method for Stock *************************************************************************************
	cout << "Stock GET/SET Method" << endl;

	cout << "*******************************************************************" << endl;
	string validName = "Juan"; //Setting name value to a string variable.
	s.SetName(validName); //Calling Stock set method and passing a string variable.
	if (validName == s.GetName()) { // Testing if the variable that was passed to the set method is return.
		cout << "Stock Get / Set Name, Valid Value : Pass" << endl;
	}
	else {
		cout << "Stock Get / Set Name, Valid Value : FAIL!" << endl;
	}

	double invalidPrice = -10; //Setting -10 to a double variable
	s.SetPrice(invalidPrice); //Calling set and passing -10
	if (invalidPrice == s.GetPrice()) { // Testing if -10 is set. 
		cout << "Stock Get / Set Price, Invalid Value : Pass" << endl;
	}
	else {
		cout << "Stock Get / Set Price, Invalid Value : FAIL!" << endl;
	}


	double invalidShare = -10; //Setting -10 to a double variable
	s.SetShare(invalidShare); //Calling set and passing -10
	if (invalidShare == s.GetShare()) { // Testing if -10 is set
		cout << "Stock Get / Set Share, Invalid Value : Pass" << endl;
	}
	else {
		cout << "Stock Get / Set Share, Invalid Value : FAIL!" << endl;
	}

	double validPrice = 10; //Setting 10 to a double variable
	s.SetPrice(validPrice); //Calling set and passing 10
	if (validPrice == s.GetPrice()) { // Testing if 10 is set
		cout << "Stock Get / Set Price, Valid Value : Pass" << endl;
	}
	else {
		cout << "Stock Get / Set Price, Valid Value : FAIL!" << endl;
	}


	double validShare = 10; //Setting 10 to a double variable
	s.SetShare(validShare); //Calling set and passing 10
	if (validShare == s.GetShare()) { // Testing if 10 is set
		cout << "Stock Get / Set Share, Valid Value : Pass" << endl;
	}
	else {
		cout << "Stock Get / Set Share, Valid Value : FAIL!" << endl;
	}

	cout << "*******************************************************************" << endl;
	//SET/GET END *******************************************************************************************


	cout << "Portfolio Method Test" << endl;

	cout << "*******************************************************************" << endl;
	Portfolio p1(4); // Constructor for Portfoilio is called. 
	Stock s2;


	s2 = s; //testing assigment operator for Stock
	int index = 3;
	p1.Set(index, s2); //Passing an int variable and a stock variable to the Set method.

	if (s2.GetName() == p1.Get(index).GetName() && s2.GetPrice() == p1.Get(index).GetPrice() && s2.GetShare() == p1.Get(index).GetShare()) //Testing if the set and get method for Profoili worked.
	{
		cout << "Portfolio Get / Set Method, Valid Value : Pass" << endl;
	}
	else {
		cout << "Portfolio Get / Set Method, Valid Value : FAIL!" << endl;
	}

	Stock s22;
	s22.SetName("nonna");
	s22.SetPrice(1);
	s22.SetShare(12);
	int in = 1;
	p1.Set(in, s22);
	p1.Set(2, s22);

	if (p1.PriceRangeCount(1, 15) == 2) //Testing if price range count matches the number inside the array.
	{
		cout << "Portfolio PriceRangeCount Method, Valid Value : Pass" << endl;
	}
	else
	{
		cout << "Portfolio PriceRangeCount Method, Valid Value : FAIL!" << endl;
	}

	//testing if Mostshare works.
	if (s22.GetName() == p1.MostShares().GetName() && s22.GetPrice() == p1.MostShares().GetPrice() && s22.GetShare() == p1.MostShares().GetShare())
	{
		cout << "Portfolio MostShares Method, Valid Value : Pass" << endl;
	}
	else
	{
		cout << "Portfolio MostShares Method, Valid Value : FAIL!" << endl;
	}

	Stock moonMan;
	if (p1.FindByName("Juan", moonMan) == true) //Testing findbyname function.
	{
		cout << "Portfolio FindByName Method, Valid Value : Pass" << endl;
	}
	else
	{
		cout << "Portfolio FindByName Method, Valid Value : FAIL!" << endl;
	}

	if (p1.TotalValue() == 112) //testing the total value of price * shares in the array and adding them. Should be 112.
	{
		cout << "Portfolio TotalValue Method, Valid Value : Pass" << endl;
	}
	else
	{
		cout << "Portfolio TotalValue Method, Valid Value : FAIL!" << endl;
	}


	p1.Resize(5); //Resizing Array.


	cout << "*******************************************************************" << endl;
	cout << "Testing Clone Function" << endl;
	cout << "*******************************************************************" << endl;
	Portfolio *c;
	c = p1.Clone(); //using cline function
	cout << *c << endl; //printing result.
	delete c; // Deleteing pointer

	StockList aba, bb,kk;
	StockList A;
	A.Add(s);
	A.Add(s);

	

	aba.Add(s22);
	aba.Add(s22);
	//bb.Add(s22); //why can't s22 be added???
	Stock h;
	cout << "*******************************************************************" << endl;

	
	aba.Add(A);
	//cout << "ABA BELOW!!!!!!!!!!!!" << endl;

	
	//cout << aba << endl;
	//aba.Delete("juan");
	cout << "ABA BELOW!!!!!!!!!!!!" << endl;
	//cout << aba << endl;
	Stock yolo;
	//cout << aba.FindByName("nonna", yolo) << endl;
	aba.FindByName("nonna", yolo);
	//cout << yolo << endl;
	cout << "*******************************************************************" << endl;
	//cout << aba.FindByName("nonna", yolo) << endl;

	StockList sl;
	std::string filename("oo.txt");
	std::ifstream infile(filename);
	//infile >> sl;
	if (infile.is_open())
		//std::cout << infile.rdbuf();
	infile >> sl;




	kk = sl;
	cout << kk << endl;

	*/



	return 0;
}