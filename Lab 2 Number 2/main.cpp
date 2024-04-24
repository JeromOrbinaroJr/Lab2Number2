#include <iostream>
#include "Stack.h"

int main() {
	char choiceMenuForOneStack;
	Stack stackFirst;
	while (true) {
		stackFirst.printMenuForOneStack();
		std::cin >> choiceMenuForOneStack;
		switch (choiceMenuForOneStack) {
		case '1':
		{
			int number;
			std::cout << "Enter element: ";
			std::cin >> number;
			stackFirst.push(number);
			stackFirst.printStack();
			break;
		}
		case '2':
			stackFirst.pop();
			stackFirst.printStack();
			break;
		case '3':
		{
			int number;
			std::cout << "Enter numeric parameter: ";
			std::cin >> number;
			stackFirst.mulVertex(number);

			break;
		}
		case '4':
			Stack stackSecond;
			char choiceMenuForMoreStacks;
			while (true) {
				stackSecond.printMenuForMoreStacks();
				std::cin >> choiceMenuForMoreStacks;

			}
		}
	}
	return 0;
}