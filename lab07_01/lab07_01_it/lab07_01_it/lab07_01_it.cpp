// lab07_01_it.cpp
// Кіц Роман Романович
// Лабораторна робота № 7.1 іт
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int col1, const int col2, const int rowCount);

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** a, const int rowCount, const int colCount)
{
	for (int j0 = 0; j0 < colCount - 1; j0++)
		for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
			if ((a[0][j1] < a[0][j1 + 1])
				||
				(a[0][j1] == a[0][j1 + 1] 
				&&
				a[1][j1] < a[1][j1 + 1])
				||
				(a[0][j1] == a[0][j1 + 1] 
				&&
				a[1][j1] == a[1][j1 + 1] 
				&&
				a[2][j1] > a[2][j1 + 1]))
				Change(a, j1, j1 + 1, rowCount);
}

void Change(int** a, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int i = 0; i < rowCount; i++)
	{
		tmp = a[i][col1];
		a[i][col1] = a[i][col2];
		a[i][col2] = tmp;
	}
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (a[i][j] % 3 == 0 && !(a[i][j] < 0))
			{
				S += a[i][j];
				k++;
				a[i][j] = 0;
			}
}

int main()
{
	srand((unsigned)time(NULL));

	int Low = -21;
	int High = 24;
	int rowCount = 9;
	int colCount = 6;

	int** a = new int* [rowCount];

	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);

	Sort(a, rowCount, colCount);
	Print(a, rowCount, colCount);

	int S = 0;
	int k = 0;

	Calc(a, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;

	Print(a, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}