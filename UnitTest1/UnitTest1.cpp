#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TEST
#include "C:\Users\Sasha\Downloads\student\vs\LR7.3iter\LR7.3iter\LR7.3iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(MatrixTests)
    {
    public:
        TEST_METHOD(CheckRowsWithoutZero)
        {
            int matrix[3][3] = {
                {1, 2, 3},
                {4, 4, 6},
                {0, 8, 9}
            };

            int* a[3] = {
                matrix[0], matrix[1], matrix[2]
            };

            Assert::AreEqual<int>(
                2, countRowsWithoutZero(a, 3, 3));
        }

        TEST_METHOD(CheckMaximumRepeated)
        {
            int matrix[3][3] = {
                {1, 4, 9},
                {4, 9, 6},
                {0, 8, 2}
            };

            int* a[3] = {
                matrix[0], matrix[1], matrix[2]
            };

            bool found = false;
            int maximum = 0;

            findMaxRepeated(a, 3, 3, found, maximum);

            Assert::IsTrue(found);
            Assert::AreEqual<int>(9, maximum);
        }

        TEST_METHOD(CheckNoRepeatedValues)
        {
            int matrix[2][3] = {
                {1, 2, 3},
                {4, 5, 6}
            };

            int* a[2] = {
                matrix[0], matrix[1]
            };

            bool found = false;
            int maximum = 0;

            findMaxRepeated(a, 2, 3, found, maximum);

            Assert::IsFalse(found);
        }

        TEST_METHOD(CheckNegativeRepeatedValues)
        {
            int matrix[2][3] = {
                {-5, -2, -5},
                {-2, -9, -8}
            };

            int* a[2] = {
                matrix[0], matrix[1]
            };

            bool found = false;
            int maximum = 0;

            findMaxRepeated(a, 2, 3, found, maximum);

            Assert::IsTrue(found);
            Assert::AreEqual<int>(-2, maximum);
        }
    };
}