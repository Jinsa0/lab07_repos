// lab07_02_it.cpp
// Кіц Роман Романович
// Лабораторна робота № 7.2 іт
// Опрацювання багатовимірних масивів ітераційним способами.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int findMax(int** a, const int k, const int j);
bool SearchMinMax(int** a, const int k, const int n, int& minMax);

void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

int findMax(int** a, const int k, const int j)
{
	int max = a[0][j]; 

	for (int i = 1; i < k; i++)
	{
		if (a[i][j] > max)
		{
			max = a[i][j];
		}
	}

	return max;
}

bool SearchMinMax(int** a, const int k, const int n, int& minMax)
{
	// У матриці немає жодного непарного стовбця
	if (n < 2)
		return false;

	minMax = findMax(a, k, 1);
	for (int j = 3; j < n; j+=2)
	{
			int currentMax = findMax(a, k, j);
			if (currentMax < minMax)
				minMax = currentMax;
	}
	return true;
}


int main()
{
	srand((unsigned)time(NULL));

	int Low = -50;
	int High = 50;

	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];

	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Create(a, k, n, Low, High);
	Print(a, k, n);

	int minMax;
	if (SearchMinMax(a, k, n, minMax))
		cout << "minMax = " << minMax << endl;
	else
		cout << "there are no odd columns" << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}