#include <iostream>
#include "Stack.h"
#include "Node.h"

//Constructors
Stack::Stack() : m_top(nullptr) {}

Stack::Stack(const std::initializer_list<int>& values) : m_top(nullptr) {
	for (int value : values) {
		push(value);
	}
}

Stack::Stack(const Stack& other) {
	m_top = new Node;
	m_top->data = other.m_top->data;
	m_top->next = nullptr;

	Node* current = m_top;
	Node* otherCurrent = other.m_top->next;
	while (otherCurrent != nullptr) {
		current->next = new Node;
		current->next->data = otherCurrent->data;
		current->next->next = nullptr;
		current = current->next;
		otherCurrent = otherCurrent->next;
	}
}

//Destructor
Stack::~Stack() {
	while (m_top != nullptr); {
		pop();
	}
}

//Methods
void Stack::push(int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = m_top;
	m_top = newNode;
}

void Stack::pop() {
	if (isEmpty()) {
		std::cout << "Stack is empty, Cannot pop." << std::endl;
		throw std::runtime_error("Stack is empty, Cannot pop.");
	}
	Node* temp = m_top;
	m_top = m_top->next;
	delete temp;
}

int& Stack::peek() {
	if (isEmpty()) {
		std::cout << "Stack is empty!" << std::endl;
		throw std::runtime_error("Stack is empty!");
	}
	return m_top->data;
}


bool Stack::isEmpty() const {
	return m_top == nullptr;
}

void Stack::printStack(std::ostream& os) const {
	Node* current = m_top;
	while (current != nullptr) {
		os << current->data << std::endl;
		current = current->next;
	}
}

int Stack::size() const {
	int count = 0;
	Node* current = m_top;
	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}

//bool Stack::isEqual(const Stack& otherStack) const {
//	if (size() != otherStack.size()) {
//		return false;
//	}
//	Stack firstCopy(*this);
//	Stack secondCopy(otherStack);
//	while (!firstCopy.isEmpty() && !secondCopy.isEmpty()) {
//		if (firstCopy.peek() != secondCopy.peek()) {
//			return false;
//		}
//		firstCopy.pop();
//		secondCopy.pop();
//	}
//	return true;
//}

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
}

//Operators Overloading
std::ostream& operator<<(std::ostream& os, Stack& stack) {
	if (stack.isEmpty()) { throw std::invalid_argument("Stack is empty!"); }
	os << "Stack elements:" << std::endl;
	stack.printStack(os);
	return os;
}

Stack& Stack::operator+=(const int& value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = m_top;
	m_top = newNode;
	return *this;
}

Stack& Stack::operator-() {
	if (isEmpty()) { throw std::invalid_argument("Stack is empty, Cannot pop."); }
	Node* temp = m_top;
	m_top = m_top->next;
	delete temp;
	return *this;
}

Stack& Stack::operator*(const int& value) {
	if (isEmpty()) { throw std::invalid_argument("Stack is empty."); }
	m_top->data *= value;
	return *this;
}

Stack& Stack::operator=(Stack& otherStack) {
	while (!isEmpty()) { pop(); }
	while (!otherStack.isEmpty()) {
		push(otherStack.peek());
		otherStack.pop();
	}
	return *this;
}

bool Stack::operator==(const Stack& otherStack) const {
	if (size() != otherStack.size()) { return false; }
	Node* thisCurrent = m_top;
	Node* otherCurrent = otherStack.m_top;
	while (thisCurrent != nullptr && otherCurrent != nullptr) {
		if (thisCurrent->data != otherCurrent->data) {
			return false;
		}
		thisCurrent = thisCurrent->next;
		otherCurrent = otherCurrent->next;
	}
	return true;
}

bool Stack::operator!=(const Stack& otherStack) const {
	if (size() != otherStack.size()) { return true; }
	Node* thisCurrent = m_top;
	Node* otherCurrent = otherStack.m_top;
	while (thisCurrent != nullptr && otherCurrent != nullptr) {
		if (thisCurrent->data != otherCurrent->data) {
			return true;
		}
		thisCurrent = thisCurrent->next;
		otherCurrent = otherCurrent->next;
	}
	return false;
}


