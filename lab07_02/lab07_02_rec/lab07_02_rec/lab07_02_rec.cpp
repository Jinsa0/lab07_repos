// lab07_02_rec.cpp
// Кіц Роман Романович
// Лабораторна робота № 7.2 рек
// Опрацювання багатовимірних масивів рекурсивним способом.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo);
void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo);

void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int K, const int N, int rowNo);

int findMaxRec(int** a, const int K, const int j, int i, int maxVal);
bool SearchMinMax(int** a, const int K, const int N, int j, int& minMax);

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int K, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, N, Low, High, 0);
	if (rowNo < K - 1)
		CreateRows(a, K, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}

void PrintRows(int** a, const int K, const int N, int rowNo)
{
	PrintRow(a, rowNo, N, 0);
	if (rowNo < K - 1)
		PrintRows(a, K, N, rowNo + 1);
	else
		cout << endl;
}

// Пошук максимуму в j-му стовпці (i - поточний рядок)
int findMaxRec(int** a, const int K, const int j, int i, int maxVal)
{
	if (i == 0)
		maxVal = a[0][j];
	else if (a[i][j] > maxVal)
		maxVal = a[i][j];

	if (i < K - 1)
		return findMaxRec(a, K, j, i + 1, maxVal);
	else
		return maxVal;
}

// Пошук мінімуму серед максимумів непарних стовпців (j = 1, 3, 5, ...)
bool SearchMinMax(int** a, const int K, const int N, int j, int& minMax)
{
	if (N < 2 || j >= N)
		return false;

	int currentMax = findMaxRec(a, K, j, 0, a[0][j]);

	if (j == 1)
	{
		minMax = currentMax;
	}
	else if (currentMax < minMax)
	{
		minMax = currentMax;
	}

	if (j + 2 < N)
		return SearchMinMax(a, K, N, j + 2, minMax);
	else
		return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int K, N;
	cout << "K = "; cin >> K;
	cout << "N = "; cin >> N;
	cout << endl;

	int** a = new int* [K];
	for (int i = 0; i < K; i++)
		a[i] = new int[N];

	int Low = -50, High = 50;
	CreateRows(a, K, N, Low, High, 0);
	PrintRows(a, K, N, 0);

	int minMax;
	if (SearchMinMax(a, K, N, 1, minMax))
	{
		cout << "minMax = " << minMax << endl;
	}
	else
	{
		cout << "there are no odd columns" << endl;
	}

	for (int i = 0; i < K; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}