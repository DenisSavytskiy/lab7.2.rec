#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab№7.2.рек/AP_Lab№7.2.рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:
        TEST_METHOD(TestSearchMin)
        {
            // Створюємо тестову матрицю 3x3
            const int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            // Заповнюємо матрицю тестовими даними
            a[0][0] = 4;  // елементи головної діагоналі
            a[1][1] = 7;
            a[2][2] = -3;

            // Інші елементи
            a[0][1] = 1; a[0][2] = 8;
            a[1][0] = 3; a[1][2] = 5;
            a[2][0] = 9; a[2][1] = 6;

            // Перевіряємо результат
            int result = SearchMin(a, n, 1, a[0][0]);
            Assert::AreEqual(-3, result);

            // Звільняємо пам'ять
            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}