#include <iostream>
#include "Stack.h"

int main() {
	int choiceMenuForOneStack;
	Stack stackFirst;
	Stack stackSecond = { 5, 4, 3, 2, 1 };

	while (true) {
		stackFirst.printMenuForOneStack();
		std::cin >> choiceMenuForOneStack;
		try {
			if (choiceMenuForOneStack < 1 || choiceMenuForOneStack > 5) { throw choiceMenuForOneStack; }
			switch (choiceMenuForOneStack) {
			case '1':
			{
				int number;
				std::cout << "Enter element: ";
				std::cin >> number;
				stackFirst.push(number);
				std::cout << stackFirst;
				break;
			}
			case '2':
				stackFirst.pop();
				std::cout << stackFirst;
				break;
			case '3':
			{
				int number;
				std::cout << "Enter numeric parameter: ";
				std::cin >> number;
				stackFirst.mulVertex(number);
				std::cout << stackFirst;
				break;
			}
			case '4':
				char choiceMenuForMoreStacks;
				while (true) {
					stackSecond.printMenuForMoreStacks();
					std::cin >> choiceMenuForMoreStacks;
					switch (choiceMenuForMoreStacks) {
					case '1':
						std::cout << "First Stack elements\n";
						std::cout << stackFirst;
						std::cout << "Second Stack elements\n";
						std::cout << stackSecond;

						stackFirst.assignStacks(stackFirst, stackSecond);

						std::cout << "First Stack elements\n";
						std::cout << stackFirst;
						break;

					case '2':
						if (stackFirst.isEqual(stackFirst, stackSecond)) {
							std::cout << "The stacks are equal.\n";
						} else {
							std::cout << "The stacks are not equal.\n";
						}
					}
					if (choiceMenuForMoreStacks == '3') {
						break;
					}
				}
			case '5':
				return 0;
			}
		}
		catch (std::exception ex){
			throw;
			std::cout << "Error" << std::endl;
		}
	}
	return 0;
}