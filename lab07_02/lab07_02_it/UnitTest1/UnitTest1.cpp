#include "pch.h"
#include "CppUnitTest.h"
#include "../lab07_02_it/lab07_02_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72It
{
	TEST_CLASS(UnitTest72It)
	{
	public:

		// 1. Тест перевіряє функцію findMax (пошук максимуму у заданому стовпці)
		TEST_METHOD(TestFindMax)
		{
			const int k = 3;
			const int n = 3;

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			// Стовпець 1: 5, 12, -3 -> Максимум = 12
			a[0][0] = 1;  a[0][1] = 5;  a[0][2] = 2;
			a[1][0] = 4;  a[1][1] = 12; a[1][2] = 6;
			a[2][0] = -1; a[2][1] = -3; a[2][2] = 0;

			int maxVal = findMax(a, k, 1);

			Assert::AreEqual(12, maxVal);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		// 2. Тест перевіряє знаходження minMax у матриці з двома непарними стовпцями (j=1 та j=3)
		TEST_METHOD(TestSearchMinMax_Success)
		{
			const int k = 2;
			const int n = 4;

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			// Стовпець 1: max = 15
			// Стовпець 3: max = 8
			// Очікуваний minMax: min(15, 8) = 8
			a[0][0] = 0; a[0][1] = 10; a[0][2] = 0; a[0][3] = 8;
			a[1][0] = 0; a[1][1] = 15; a[1][2] = 0; a[1][3] = -2;

			int minMax = 0;
			bool result = SearchMinMax(a, k, n, minMax);

			Assert::IsTrue(result);
			Assert::AreEqual(8, minMax);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		// 3. Тест перевіряє випадок, коли в матриці немає жодного непарного стовпця (n < 2)
		TEST_METHOD(TestSearchMinMax_NoOddColumns)
		{
			const int k = 2;
			const int n = 1; // У матриці лише стовпець 0 (немає стовпця з індексом 1)

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			a[0][0] = 5;
			a[1][0] = 10;

			int minMax = 0;
			bool result = SearchMinMax(a, k, n, minMax);

			Assert::IsFalse(result);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		// 4. Тест перевіряє коректне порівняння трьох непарних стовпців (j=1, j=3, j=5)
		TEST_METHOD(TestSearchMinMax_MultipleOddColumns)
		{
			const int k = 2;
			const int n = 6;

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			// Стовпець 1: max = 20
			// Стовпець 3: max = 5
			// Стовпець 5: max = 12
			// Очікуваний minMax: min(20, 5, 12) = 5
			a[0][0] = 0; a[0][1] = 20; a[0][2] = 0; a[0][3] = 1;  a[0][4] = 0; a[0][5] = 12;
			a[1][0] = 0; a[1][1] = -5; a[1][2] = 0; a[1][3] = 5;  a[1][4] = 0; a[1][5] = 3;

			int minMax = 0;
			bool result = SearchMinMax(a, k, n, minMax);

			Assert::IsTrue(result);
			Assert::AreEqual(5, minMax);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

	};
}