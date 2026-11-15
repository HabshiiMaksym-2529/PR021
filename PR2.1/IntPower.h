#pragma once

class IntPower
{
private:
    double first = 1.0;
    int second = 0;

public:
    double GetFirst() const;
    int GetSecond() const;

    bool SetFirst(double value);
    void SetSecond(int value);

    bool Init(double base, int exponent);
    void Read();
    void Display() const;

    double power() const;
};

IntPower makeIntPower(double base, int exponent);