// Lab_7.3.2.cpp
// Обухов Віктор
// Лабораторна робота № 7.3
// Опрцюання динаміних бгатовмірних маивів масивів (ітерація)
// Варіант 7

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

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

int Sum(int** a, const int rowCount, const int colCount)
{
	int S = 0, x;

	for (int i = 0; i < rowCount; i++)
	{
		x = 0;
		for (int j = 0; j < colCount; j++)
			if (a[i][j] < 0)
			{
				x++;
				break;
			}
		if (x > 0)
		{
			for (int j = 0; j < colCount; j++)
				S += a[i][j];
		}
	}
	return S;
}

int min()
{
	srand((unsigned)time(NULL));

	int Low = -20;
	int High = 25;

	int rowCount, colCount;

	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** arr = new int* [rowCount];

	for (int i = 0; i < rowCount; i++)
		arr[i] = new int[colCount];

	Create(arr, rowCount, colCount, Low, High);
	Print(arr, rowCount, colCount);

	int S = Sum(arr, rowCount, colCount);
	cout << "Sum = " << S << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}