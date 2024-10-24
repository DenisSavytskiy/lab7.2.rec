// Lab_7_2_2.cpp
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 27
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo);
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo);
void PrintRow(int** a, const int rowNo, const int N, int colNo);
void PrintRows(int** a, const int N, int rowNo);
int SearchMin(int** a, const int N, int i, int min);

int main()
{
    srand((unsigned)time(NULL));
    int N;
    cout << "N = "; cin >> N;
    cout << endl;

    int** a = new int* [N];
    for (int i = 0; i < N; i++)
        a[i] = new int[N];

    int Low = -20, High = 20;
    CreateRows(a, N, Low, High, 0);
    PrintRows(a, N, 0);

    int minElement = SearchMin(a, N, 1, a[0][0]);
    cout << "min element in main diagonal = " << minElement << endl;

    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, rowNo + 1);
    else
        cout << endl;
}

int SearchMin(int** a, const int N, int i, int min)
{
    // Базовий випадок: якщо досягли кінця матриці
    if (i >= N)
        return min;

    // Якщо поточний елемент головної діагоналі менший за мінімальний
    if (a[i][i] < min)
        min = a[i][i];

    // Рекурсивний виклик для наступного елемента діагоналі
    return SearchMin(a, N, i + 1, min);
}