#include "StockQueue.h"

StockQueue::StockQueue()
{
	front = NULL;
	rear = NULL;
}

StockQueue::StockQueue(const StockQueue & rhs)
{
	size = 0;
	QueNode *temp;
	temp = rhs.front;
	while (temp != NULL)
	{
		Enqueue(temp->data);
		temp = temp->next;
		//size--;
	}
}

StockQueue::~StockQueue()
{

	Clear();
}

void StockQueue::Clear()
{
	QueNode * temp;

	while (front != NULL)
	{
		temp = front;
		front = front->next;
		delete temp;
	}

	rear = NULL;
}

int StockQueue::Size()
{
	return size;
}

void StockQueue::Enqueue(Stock s)
{
	QueNode* temp;
	temp = new QueNode;

	temp->data = s;
	temp->next = NULL;
	if (rear == NULL)
	{
		front = temp;
	}
	else
	{
		rear->next = temp;
	}
	rear = temp;
	size++;

}

bool StockQueue::Dequeue(Stock & returnedStock)
{
	if (front != NULL)
	{
		QueNode* temp;
		temp = front;

		returnedStock = front->data;
		front = front->next;

		if (front == NULL)
			rear = NULL;
		size--;
		delete temp;
		return true;
	}
	std::cout << "Unable to Dequeue!" << std::endl;
	return false;
}

StockQueue & StockQueue::operator=(const StockQueue & rhs)
{
	// TODO: insert return statement here

	if (this == &rhs)
	{
		return *this;
	}

	Clear();
	//size = rhs.size;
	QueNode *temp;
	temp = rhs.front;
	while (temp != NULL)
	{
		Enqueue(temp->data);
		temp = temp->next;
		//size--;
	}

	return *this;


}

std::ostream & operator<<(std::ostream & os, StockQueue & ref)
{
	StockQueue::QueNode *temp, *u;
	temp = ref.front;
	
	while (temp != NULL)
	{
		os << temp->data << std::endl;
		temp = temp->next;

	}
	return os;
}
