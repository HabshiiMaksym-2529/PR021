#include "pch.h"
#include "CppUnitTest.h"
#include "E:\Документи\навчання\2 курс ООП\PR2.x\PR2.1\IntPower.h"
#include "E:\Документи\навчання\2 курс ООП\PR2.x\PR2.1\IntPower.cpp"
#include "E:\Документи\навчання\2 курс ООП\PR2.x\PR2.1\PR2.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntPowerTests
{
    TEST_CLASS(IntPowerTests)
    {
    public:
        TEST_METHOD(Power_NegativeBaseAndNegativeExponent)
        {
            IntPower number;
            number.Init(-2.0, -3);

            const double actual = number.power();

            Assert::AreEqual(-0.125, actual, 1e-12);
        }
    };
}