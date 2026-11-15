#include "IntPower.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

double IntPower::GetFirst() const
{
    return first;
}

int IntPower::GetSecond() const
{
    return second;
}

bool IntPower::SetFirst(double value)
{
    if (!std::isfinite(value) || value == 0.0)
    {
        return false;
    }

    first = value;
    return true;
}

void IntPower::SetSecond(int value)
{
    // Будь-яке значення типу int є допустимим показником.
    second = value;
}

bool IntPower::Init(double base, int exponent)
{
    if (!SetFirst(base))
    {
        return false;
    }

    SetSecond(exponent);
    return true;
}

void IntPower::Read()
{
    std::string line;

    while (true)
    {
        std::cout << "Enter the base and an integer exponent: ";

        if (!std::getline(std::cin, line))
        {
            std::cerr << "Input ended before a valid pair was entered.\n";
            std::exit(EXIT_FAILURE);
        }

        std::istringstream input(line);
        double base;
        int exponent;
        char extra;

        if ((input >> base >> exponent) && !(input >> extra)
            && Init(base, exponent))
        {
            return;
        }

        std::cout << "Enter a nonzero finite base and an integer exponent.\n";
    }
}

void IntPower::Display() const
{
    std::cout << "Base: " << GetFirst() << '\n';
    std::cout << "Exponent: " << GetSecond() << '\n';
}

double IntPower::power() const
{
    return std::pow(GetFirst(), GetSecond());
}

IntPower makeIntPower(double base, int exponent)
{
    IntPower object;

    if (!object.Init(base, exponent))
    {
        std::cerr << "Error: the base must be finite and nonzero.\n";
        std::exit(EXIT_FAILURE);
    }

    return object;
}