#include "pch.h"
#include "CppUnitTest.h"
#include "../lab07_01_it/lab07_01_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71
{
	TEST_CLASS(UnitTest71)
	{
	public:

		// 1. Тест перевіряє обчислення суми елементів (усі кратні 3, крім від'ємних)
		TEST_METHOD(TestCalcSum)
		{
			const int rowCount = 2;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			// Рядок 0: -6,  3,  0  (підходять 3 і 0)
			// Рядок 1:  9, -3,  5  (підходить 9)
			a[0][0] = -6; a[0][1] = 3; a[0][2] = 0;
			a[1][0] = 9;  a[1][1] = -3; a[1][2] = 5;

			int sum = 0;
			int count = 0;

			Calc(a, rowCount, colCount, sum, count);

			// Очікувана сума: 3 + 0 + 9 = 12
			Assert::AreEqual(12, sum);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		// 2. Тест перевіряє підрахунок кількості підходящих елементів
		TEST_METHOD(TestCalcCount)
		{
			const int rowCount = 2;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = -6; a[0][1] = 3; a[0][2] = 0;
			a[1][0] = 9;  a[1][1] = -3; a[1][2] = 5;

			int sum = 0;
			int count = 0;

			Calc(a, rowCount, colCount, sum, count);

			// Очікувана кількість: 3 елементи (3, 0, 9)
			Assert::AreEqual(3, count);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		// 3. Тест перевіряє заміну підходящих елементів нулями
		TEST_METHOD(TestCalcZeroReplacement)
		{
			const int rowCount = 2;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = -6; a[0][1] = 3; a[0][2] = 0;
			a[1][0] = 9;  a[1][1] = -3; a[1][2] = 5;

			int sum = 0;
			int count = 0;

			Calc(a, rowCount, colCount, sum, count);

			// Перевіряємо, що елементи 3, 0, 9 обнулилися, а інші залишилися незмінними
			Assert::AreEqual(-6, a[0][0]); // Не змінився (від'ємне)
			Assert::AreEqual(0, a[0][1]); // Обнулився (було 3)
			Assert::AreEqual(0, a[0][2]); // Обнулився (було 0)
			Assert::AreEqual(0, a[1][0]); // Обнулився (було 9)
			Assert::AreEqual(-3, a[1][1]); // Не змінився (від'ємне)
			Assert::AreEqual(5, a[1][2]); // Не змінився (не ділиться на 3)

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

	};
}