#include <iostream>
#include "Stack.h"
#include "Node.h"

//Constructor
Stack::Stack() : top(nullptr) {}

Stack::Stack(const std::initializer_list<int>& values) : top(nullptr) {
	for (int value : values) {
		push(value);
	}
}

//Destructor
Stack::~Stack() {
	while (top != nullptr) {
		pop();
	}
}

//Methods
void Stack::push(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = top;
	top = newNode;
}

void Stack::push(double value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = top;
	top = newNode;
}

void Stack::pop() {
	try {
		if (isEmpty()) { throw; }
		Node* temp = top;
		top = top->next;
		delete temp;
	} catch (std::exception ex) {
		std::cout << "Stack is empty, Cannot pop." << std::endl;
		return;
	}
}

int Stack::peek() {
	try {
		if (isEmpty()) { throw; }
		return top->data;
	} catch (std::exception ex) {
		std::cout << "Stack is empty. Cannot peek." << std::endl;
		return -1;
	}
}

bool Stack::isEmpty() {
	return top == nullptr;
}

void Stack::printStack(std::ostream& os) const {;
	Node* current = top;
	while (current != nullptr) {
		os << current->data << std::endl;
		current = current->next;
	}
}

std::ostream& operator<<(std::ostream& os, Stack& stack) {
	if (stack.isEmpty()) {
		os << "Stack is empty." << std::endl;
	}
	os << "Stack elements:" << std::endl;
	stack.printStack(os);
	return os;
}


void Stack::mulVertex(int value) {
	try{
		if (isEmpty()) { throw value; }
		top->data *= value;
	}
	catch (int value) {
		std::cout << "Stack is empty.\n";
	}
}
void Stack::mulVertex(double value) {
	try {
		if (isEmpty()) { throw value; }
		top->data *= value;
	}
	catch (int value) {
		std::cout << "Stack is empty.\n";
	}
}

void Stack::assignStacks(Stack& inStack, Stack& outStack) {
	while (!inStack.isEmpty()) {
		inStack.pop();
	}
	while (!outStack.isEmpty()) {
		inStack.push(outStack.peek());
		outStack.pop();
	}
}

int Stack::size() const {
	int count = 0;
	Node* current = top;
	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}

bool Stack::isEqual(const Stack& firstStack, const Stack& secondStack) const {
	if (firstStack.size() != secondStack.size()) {
		return false;
	}
	Stack firstCopy = firstStack;
	Stack secondCopy = secondStack;
	while (!firstCopy.isEmpty() && !secondCopy.isEmpty()) {
		if (firstCopy.peek() != secondCopy.peek()) {
			return false;
		}
		firstCopy.pop();
		secondCopy.pop();
	}
	return true;
}


void Stack::printMenuForOneStack() {
	std::cout << "1) Add an element to stack. \n";
	std::cout << "2) Remove the top element from the stack. \n";
	std::cout << "3) Multiply the top of the stack by any parameter. \n";
	std::cout << "4) Create a new stack. \n";
	std::cout << "5) Exit the program.\n";
}

void Stack::printMenuForMoreStacks() {
	std::cout << "1) Assign stack First to stack Second.\n";
	std::cout << "2) Are the two stacks equal?\n";
	std::cout << "3) Return to menu for one stack.\n";
}