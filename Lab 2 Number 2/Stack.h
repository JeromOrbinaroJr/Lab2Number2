#pragma once 
#include "Node.h"

class Stack {
public:
	Stack();
	~Stack();

	void push(int value);
	void push(double value);
	void pop();
	int peek();
	bool isEmpty();
	void printStack();
	void mulVertex(int value);
	void mulVertex(double value);

	void printMenuForOneStack();
	void printMenuForMoreStacks();
private:
	Node* top;
};
