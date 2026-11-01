#include "pch.h"
#include "CppUnitTest.h"
#include "../lab07_02_rec/lab07_02_rec.cpp" // Перевірте відносний шлях до файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab0702Rec
{
    TEST_CLASS(UnitTestLab0702Rec)
    {
    public:

        // Тест 1: Перевірка знаходження максимуму в окремому стовпці (findMaxRec)
        TEST_METHOD(TestFindMaxRec)
        {
            const int K = 3;
            const int N = 3;

            int** a = new int* [K];
            for (int i = 0; i < K; i++)
                a[i] = new int[N];

            // Матриця 3x3:
            //  5   12   -3
            // -8   45    0
            // 10    7   18
            a[0][0] = 5;  a[0][1] = 12; a[0][2] = -3;
            a[1][0] = -8; a[1][1] = 45; a[1][2] = 0;
            a[2][0] = 10; a[2][1] = 7;  a[2][2] = 18;

            // Перевіряємо максимум у 1-му стовпці (j = 1), який дорівнює 45
            int maxCol1 = findMaxRec(a, K, 1, 0, a[0][1]);
            Assert::AreEqual(45, maxCol1);

            // Перевіряємо максимум у 0-му стовпці (j = 0), який дорівнює 10
            int maxCol0 = findMaxRec(a, K, 0, 0, a[0][0]);
            Assert::AreEqual(10, maxCol0);

            for (int i = 0; i < K; i++)
                delete[] a[i];
            delete[] a;
        }

        // Тест 2: Пошук мінімуму серед максимумів непарних стовпців (SearchMinMax)
        TEST_METHOD(TestSearchMinMax)
        {
            const int K = 3;
            const int N = 4;

            int** a = new int* [K];
            for (int i = 0; i < K; i++)
                a[i] = new int[N];

            // Матриця 3x4:
            // Індекси стовпців: 0, 1, 2, 3
            // Непарні стовпці: j = 1 та j = 3
            //  10   20   30   40
            //  -5   15    5   25
            //   0    8   12   30
            // Максимум j=1: 20
            // Максимум j=3: 40
            // Очікуваний minMax = min(20, 40) = 20

            a[0][0] = 10; a[0][1] = 20; a[0][2] = 30; a[0][3] = 40;
            a[1][0] = -5; a[1][1] = 15; a[1][2] = 5;  a[1][3] = 25;
            a[2][0] = 0;  a[2][1] = 8;  a[2][2] = 12; a[2][3] = 30;

            int minMax = 0;
            bool result = SearchMinMax(a, K, N, 1, minMax);

            Assert::IsTrue(result);
            Assert::AreEqual(20, minMax);

            for (int i = 0; i < K; i++)
                delete[] a[i];
            delete[] a;
        }

        // Тест 3: Випадок, коли непарних стовпців немає (N < 2)
        TEST_METHOD(TestNoOddColumns)
        {
            const int K = 2;
            const int N = 1; // Тільки один стовпець (j = 0)

            int** a = new int* [K];
            for (int i = 0; i < K; i++)
                a[i] = new int[N];

            a[0][0] = 10;
            a[1][0] = 20;

            int minMax = 0;
            bool result = SearchMinMax(a, K, N, 1, minMax);

            // Функція має повернути false, оскільки немає непарного стовпця j=1
            Assert::IsFalse(result);

            for (int i = 0; i < K; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}