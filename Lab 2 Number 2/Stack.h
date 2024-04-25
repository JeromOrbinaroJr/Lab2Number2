#pragma once 
#include "Node.h"
#include <iostream>

class Stack {
public:
	//Constructor
	Stack();

	Stack(const std::initializer_list<int>& values);

	//Destructor
	~Stack();

	//Methods
	void push(int value);
	void push(double value);
	void pop();
	int peek();
	int size() const;
	bool isEmpty();
	bool isEqual(const Stack& firstStack, const Stack& secondStack) const;
	void printStack(std::ostream& os) const;
	friend std::ostream& operator<<(std::ostream& os, Stack& stack);
	void mulVertex(int value);
	void mulVertex(double value);
	void assignStacks(Stack& inStack, Stack& outStack);

	void printMenuForOneStack();
	void printMenuForMoreStacks();
private:
	Node* top;
};
