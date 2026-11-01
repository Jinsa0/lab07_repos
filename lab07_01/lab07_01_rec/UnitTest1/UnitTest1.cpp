#include "pch.h"
#include "CppUnitTest.h"
#include "../lab07_01_rec/lab07_01_rec.cpp" // Підключення файлу з рекурсивною реалізацією

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71Rec
{
	TEST_CLASS(UnitTest71Rec)
	{
	public:

		// 1. Тест рекурсивного обчислення суми елементів (усі кратні 3, крім від'ємних)
		TEST_METHOD(TestCalcSumRecursive)
		{
			const int rowCount = 2;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			// Рядок 0: -6,  3,  0  (підходять 3 і 0)
			// Рядок 1:  9, -3,  5  (підходить 9)
			a[0][0] = -6; a[0][1] = 3;  a[0][2] = 0;
			a[1][0] = 9;  a[1][1] = -3; a[1][2] = 5;

			int sum = 0;
			int count = 0;

			// Виклик головної рекурсивної функції з початковим індексом рядка 0
			CalcRows(a, rowCount, colCount, 0, sum, count);

			// Очікувана сума: 3 + 0 + 9 = 12
			Assert::AreEqual(12, sum);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		// 2. Тест рекурсивного підрахунку кількості підходящих елементів
		TEST_METHOD(TestCalcCountRecursive)
		{
			const int rowCount = 2;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = -6; a[0][1] = 3;  a[0][2] = 0;
			a[1][0] = 9;  a[1][1] = -3; a[1][2] = 5;

			int sum = 0;
			int count = 0;

			CalcRows(a, rowCount, colCount, 0, sum, count);

			// Очікувана кількість: 3 елементи (3, 0, 9)
			Assert::AreEqual(3, count);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		// 3. Тест рекурсивної заміни підходящих елементів нулями
		TEST_METHOD(TestCalcZeroReplacementRecursive)
		{
			const int rowCount = 2;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = -6; a[0][1] = 3;  a[0][2] = 0;
			a[1][0] = 9;  a[1][1] = -3; a[1][2] = 5;

			int sum = 0;
			int count = 0;

			CalcRows(a, rowCount, colCount, 0, sum, count);

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

		// 4. Тест рекурсивного сортування стовпчиків матриці (за 3 ключами Варіанта 12)
		TEST_METHOD(TestSortRecursive)
		{
			const int rowCount = 3;
			const int colCount = 3;

			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			// Початкова матриця стовпчиків:
			// Стовпець 0: [ 5, 10, 2 ]
			// Стовпець 1: [ 8,  4, 1 ]
			// Стовпець 2: [ 8,  4, 9 ]
			// За правилом Варіанта 12: 
			// 1-й рядок за спаданням -> 8, 8, 5
			// 2-й рядок за спаданням -> при рівних 8 порівнюємо 4 і 4 (рівні)
			// 3-й рядок за зростанням -> при рівних (8, 4) порівнюємо 1 і 9 -> 1 має бути раніше за 9

			a[0][0] = 5; a[0][1] = 8; a[0][2] = 8;
			a[1][0] = 10;a[1][1] = 4; a[1][2] = 4;
			a[2][0] = 2; a[2][1] = 9; a[2][2] = 1;

			// Виклик рекурсивного сортування
			Sort(a, rowCount, colCount, 0);

			// Очікуваний порядок стовпчиків після сортування:
			// Стовпець 0 має бути колишнім Стовпцем 1 ([8, 4, 1])
			// Стовпець 1 має бути колишнім Стовпцем 2 ([8, 4, 9])
			// Стовпець 2 має бути колишнім Стовпцем 0 ([5, 10, 2])

			Assert::AreEqual(8, a[0][0]);
			Assert::AreEqual(4, a[1][0]);
			Assert::AreEqual(1, a[2][0]);

			Assert::AreEqual(8, a[0][1]);
			Assert::AreEqual(4, a[1][1]);
			Assert::AreEqual(9, a[2][1]);

			Assert::AreEqual(5, a[0][2]);
			Assert::AreEqual(10, a[1][2]);
			Assert::AreEqual(2, a[2][2]);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

	};
}