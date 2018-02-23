#include "StockStack.h"

StockStack::StockStack()
{
	
	top = -1;

	m_array = new Stock[STOCK_ARRAY];

	for (int i = 0; i < STOCK_ARRAY; i++)
	{
		m_array[i].SetName("");
		m_array[i].SetPrice(0);
		m_array[i].SetShare(0);
	}

	

}

StockStack::StockStack(int max) //works
{
	top = -1;
	STOCK_ARRAY = max;
	if (max < 0 )
	{
		std::cout << "Enter a positive number" << std::endl;
		return;
	}
	m_array = new Stock[STOCK_ARRAY];
	for (int i = 0; i < STOCK_ARRAY; i++)
	{
		m_array[i].SetName("");
		m_array[i].SetPrice(0);
		m_array[i].SetShare(0);
	}

}

StockStack::StockStack(const StockStack & rhs) //unsure
{
	STOCK_ARRAY = rhs.STOCK_ARRAY;
	top = rhs.top;
	m_array = new Stock[rhs.STOCK_ARRAY];
	for (int i = 0; i < STOCK_ARRAY; i++)
	{
		m_array[i] = rhs.m_array[i];
	}
}

StockStack::~StockStack() //works
{
	delete[] m_array;
}

void StockStack::Clear() //Works
{
	top = -1;
	STOCK_ARRAY = 0;
	
}

int StockStack::Size() //works fine
{
	return top+1;
}

int StockStack::MaxStorage() //works fine
{
	return STOCK_ARRAY;
}

bool StockStack::Push(Stock s) //works fine
{
	if (top == (STOCK_ARRAY - 1))
	{
		std::cout << "Can't add more items. Pop an old item!" << std::endl;
		return false;
	}
	else
	{
		top++;
		m_array[top] = s;
		return true;
	}
	
}

bool StockStack::Pop()// work
{
	if (top == -1)
	{
		std::cout << "Can't delete. Is empty!" << std::endl;
		return false;
	}
	else
	{
		
		top--;
		
		return true;
	}
}

bool StockStack::Top(Stock & returnedStock) //Works!!!
{
	if (top == -1)
	{
		std::cout << "Is empty!" << std::endl;
		return false;
	}
	returnedStock= m_array[top];
	return true;
}

StockStack & StockStack::operator=(StockStack & rhs) //works
{
	// TODO: insert return statement here

	if (this == &rhs)
	{

		return *this;

	}
	delete[] m_array;
	top = rhs.top;
	STOCK_ARRAY = rhs.STOCK_ARRAY;
	m_array = new Stock[rhs.STOCK_ARRAY];
	for (int i = 0; i < STOCK_ARRAY; i++)
	{
		m_array[i] = rhs.m_array[i];
	}

	return *this;
}

std::ostream & operator<<(std::ostream & os, StockStack & ref) //	Works!!!
{
	for (int i = 0; i < ref.top +1; i++)
	{
		os << ref.m_array[i].GetName() << std::endl;
		os << ref.m_array[i].GetPrice() << std::endl;
		os << ref.m_array[i].GetShare() << std::endl;
	}
	return os;
}
