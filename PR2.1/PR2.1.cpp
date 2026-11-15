#include "IntPower.h"

#include <iostream>
#include <sstream>
#include <string>

int main()
{
    IntPower number;
    bool baseEntered = false;
    bool exponentEntered = false;
    std::string line;

    while (true)
    {
        std::cout << "\n1. Enter the base\n"
            << "2. Enter the exponent\n"
            << "3. Calculate\n"
            << "4. Exit\n"
            << "Choose an option: ";

        if (!std::getline(std::cin, line))
        {
            return 0;
        }

        std::istringstream menuInput(line);
        int option;
        char extra;

        if (!(menuInput >> option) || (menuInput >> extra))
        {
            std::cout << "Choose a number from 1 to 4.\n";
            continue;
        }

        switch (option)
        {
        case 1:
        {
            std::cout << "Enter a nonzero base: ";

            if (!std::getline(std::cin, line))
            {
                return 0;
            }

            std::istringstream input(line);
            double base;

            if (!(input >> base) || (input >> extra) || !number.SetFirst(base))
            {
                std::cout << "The base must be a finite nonzero number.\n";
                break;
            }

            baseEntered = true;
            break;
        }

        case 2:
        {
            std::cout << "Enter an integer exponent: ";

            if (!std::getline(std::cin, line))
            {
                return 0;
            }

            std::istringstream input(line);
            int exponent;

            if (!(input >> exponent) || (input >> extra))
            {
                std::cout << "The exponent must be a valid integer.\n";
                break;
            }

            number.SetSecond(exponent);
            exponentEntered = true;
            break;
        }

        case 3:
            if (!baseEntered || !exponentEntered)
            {
                std::cout << "Enter both the base and the exponent first.\n";
                break;
            }

            number.Display();
            std::cout << "Power: " << number.power() << '\n';
            break;

        case 4:
            return 0;

        default:
            std::cout << "Choose a number from 1 to 4.\n";
            break;
        }
    }
}