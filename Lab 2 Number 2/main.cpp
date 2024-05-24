#include <iostream>
#include "Stack.h"
    
int main() {
    int choiceMenuForOneStack;
    Stack stackFirst;
    Stack stackSecond = { 5, 4, 3, 2, 1 };
    try {
        while (true) {
            stackFirst.printMenuForOneStack();
            std::cin >> choiceMenuForOneStack;
            switch (choiceMenuForOneStack) {
            case 1: {
                int number;
                std::cout << "Enter element: ";
                std::cin >> number;
                stackFirst += number;
                std::cout << stackFirst;
                break;
            }
            case 2:
                -stackFirst;
                std::cout << stackFirst;
                break;
            case 3: {
                int number;
                std::cout << "Enter numeric parameter: ";
                std::cin >> number;
                stackFirst* number;
                std::cout << stackFirst;
                break;
            }
            case 4: {
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
                        stackFirst = stackSecond;
                        std::cout << "First Stack elements\n";
                        std::cout << stackFirst;
                        break;

                    case '2':
                        if (stackFirst==stackSecond) {
                            std::cout << "The stacks are equal.\n";
                        }
                        else {
                            std::cout << "The stacks are not equal.\n";
                        }
                        break;
                    default:
                        std::cout << "Error!" << std::endl;
                        break;
                    }
                }
                break;
            }
            case 5:
                return 0;
            default:
                std::cout << "Error!" << std::endl;
                break;
            }
        }
    }
    catch (const std::invalid_argument& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
