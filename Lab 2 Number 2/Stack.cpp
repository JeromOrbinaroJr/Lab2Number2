#include <iostream>
#include "Stack.h"

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
	while (top != nullptr) {
		pop();
	}
}

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
	if (isEmpty()) {
		std::cout << "Stack is empty, Cannot pop." << std::endl;
		return;
	}
	Node* temp = top;
	top = top->next;
	delete temp;
}

int Stack::peek() {
	if (isEmpty()) {
		std::cout << "Stack is empty. Cannot peek." << std::endl;
		return -1;
	}
	return top->data;
}

bool Stack::isEmpty() {
	return top == nullptr;
}

void Stack::printStack() {
	if (isEmpty()) {
		std::cout << "Stack is empty." << std::endl;
		return;
	}
	std::cout << "Stack elements: \n";
	Node* current = top;
	while (current != nullptr) {
		std::cout << current->data << "\n";
		current = current->next;
	}
	std::cout << std::endl;
}

void Stack::mulVertex(int value) {
	top->data *= value;
}
void Stack::mulVertex(double value) {
	top->data *= value;
}

void Stack::printMenuForOneStack() {
	std::cout << "1) Add an element to stack. \n";
	std::cout << "2) Remove the top element from the stack. \n";
	std::cout << "3) Multiply the top of the stack by any parameter. \n";
	std::cout << "4) Create a new stack. \n";
}

void Stack::printMenuForMoreStacks() {
	std::cout << "1) Add an element to First stack. \n";
	std::cout << "2) Add an element to Second stack. \n\n";

	std::cout << "3) Remove the top element from the First stack. \n";
	std::cout << "4) Remove the top element from the Second stack. \n\n";

	std::cout << "5) Multiply the top of the First stack by any parameter. \n";
	std::cout << "6) Multiply the top of the Second stack by any parameter. \n";
	std::cout << "[------------------------------------------------------------]\n";
	std::cout << "7) Assign stack First to stack Second.\n";
	std::cout << "8) Are the two stacks equal?\n";
	std::cout << "9) Are the two stacks not equal?\n";

}