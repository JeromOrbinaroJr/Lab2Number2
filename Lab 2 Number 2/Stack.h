#pragma once 
#include "Node.h"
#include <iostream>

class Stack {
public:
	//Constructors
	Stack();
	Stack(const std::initializer_list<int>& values);
	Stack(const Stack& other); // copy ctr

	//Destructor
	~Stack();

	//Methods
	void push(int value);
	void pop();
	int& peek();
	int size() const;
	bool isEmpty() const;
	bool isEqual(const Stack& otherStack) const;
	void printStack(std::ostream& os) const;
	void assignStacks(Stack& otherStack);

	//Menu
	void printMenuForOneStack();
	void printMenuForMoreStacks();

	//Operator Overloading
	friend std::ostream& operator<<(std::ostream& os, Stack& stack);
	Stack& operator+(const int& value);
	Stack& operator-();
	Stack& operator*(const int& value);

private:
	Node* m_top;
};
