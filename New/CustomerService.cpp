#include "CustomerService.h"
#include<ios>
#include<limits>
#include<fstream>
#include <iostream>
#include <string>
#include <cstring>
CustomerService::CustomerService()
{
	head = NULL;
	tail = head;
}
CustomerService::~CustomerService(){}
int CustomerService::cusAmount = 0;
//QUEUE
void CustomerService::enqueue()
{
	Customer* customer=new Customer();
	customer->setData();
	if (head == NULL)
	{
		head = customer;
	}
	else
	{
		tail->next = customer;
		
	}
	tail = customer;
	tail->next = head;
	cusAmount++;
}
void CustomerService::enqueue(Customer * customer)
{
	if (head == NULL)
	{
		head = customer;
	}
	else
	{
		tail->next = customer;
	}
	tail = customer;
	tail->next = head;
	cusAmount++;
}
void CustomerService::dequeue()
{

	bool check = false;
	cout << "DO YOU WANT TO DELETE?";
	int choice;
	cout << "Enter 1 to delete,0 to exit";
	cin >> choice;
	check = choice;
	if (check) {
		if (isEmpty())
		{
			cout << "List is empty";
			return;
		}	
	//	Customer* prev = head;
		if (head == tail) {
			free(head);
			head = NULL;
			tail = NULL;
		}
		else {
			Customer* temp = head;
			head = head->next;
			tail->next = head;
			free(temp);
		}
	}
}

void CustomerService::display()
{
	Customer* temp = head;
	cout << "Elements in circular list are: \n";
	while (temp->next != head)
	{
		cout << *temp;
		temp = temp->next;
	}
	cout << *temp;
}
bool CustomerService::isEmpty()
{
	if (head == NULL) return true;
	else return false;
}
bool CustomerService::contain(string MKH)
{
	Customer* temp = head;
	if (!isEmpty())
	{
		do
		{
			if (temp->MKH.compare(MKH) == 0)return true;
		} while (temp != head);
	}
	return false;
}
void CustomerService::readDataInFile(string path)
{
	ifstream file(path,ios::in);//chua gt
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			Customer* cus = new Customer();
			cus->fromString(line);
			enqueue(cus);
		}
		cout << "\ndata added successfully\n";
		file.close();
	}
	else
	{
		cout << "path is incorrect____Try again" << endl;
	}
}

