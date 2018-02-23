#include "StockList.h"


StockList::StockList()
{
	length = 0;
	listData = NULL; 
}

StockList::StockList(const StockList & otherList) //needs loop
{
	length = otherList.length;
	node *temp;
	temp = otherList.listData;
	while (temp != NULL)
	{
		Add(temp->data);
		temp = temp->next;
		length--;
	}

	//listData = temp;
	//length = otherList.length;
//	listData = otherList.listData;
}

StockList::~StockList()
{
	Clear();
}

StockList & StockList::operator=(StockList & rhs) 
{
	if (this == &rhs)
	{
		return *this;
	}

	Clear();
	length = rhs.length;
	node *temp;
	temp = rhs.listData;
	while (temp != NULL)
	{
		Add(temp->data);
		temp = temp->next;
		length--; 
	}

	return *this;
}

void StockList::Clear() 
{
	node *tempPtr;
	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}

	length = 0;
	listData = NULL;
}

int StockList::Length() const 
{
	return length;
}

void StockList::Add(const Stock s)
{
	node *temp = new node;
	temp->data = s;
	temp->next = listData;

	listData = temp;
	length++;
	
}

void StockList::Add(const StockList & otherList) 
{

	node *temp = new node;
	temp = otherList.listData;
	while (temp != NULL)
	{
		Add(temp->data);
		temp = temp->next;
	}
	
}

bool StockList::FindByName(std::string name, Stock & result) const 
{
	node *temp;
	temp = listData;
	while (temp != NULL  )
	{
		if (name == temp->data.GetName())
		{
			result = temp->data;
			return true;
		}
		temp = temp->next;
	}
	
	return false;
}

void StockList::Delete(std::string name)
{
	
	node *location;
	node *tempLocation;
	location = listData; // points to the head
	while ((location->next != NULL) && (name != (location->next)->data.GetName()))
	{
		location = location->next;
	}
	if (location->next == NULL)
	{ 
		std::cout << "Name was not in the list" << std::endl;
		return; 
	} 

	tempLocation = location->next;
	location->next = (location->next)->next;
	delete tempLocation;

	length--;

}

std::ostream & operator<<(std::ostream & os, StockList & ref) 
{
	StockList::node *temp;
	temp = ref.listData;
	while (temp !=NULL)
	{
		os << temp->data << std::endl;
		temp = temp->next;
		
	}
	return os;


}

std::istream & operator >> (std::istream & is, StockList & rhs) 
{
	std::string name;
	double price, share;
	Stock temp;
	
	while (!is.eof())
	{
		is >> name >> price >> share;
		temp.SetName(name);
		temp.SetPrice(price);
		temp.SetShare(share);
		rhs.Add(temp);
		
	}


	
	return is;
}
