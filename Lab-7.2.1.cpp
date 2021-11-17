#include <iostream>
#include <iomanip>
using namespace std;

void Create(int** arr, const int rowCount, const int colCount, const int Low = -10, const int High = 10);
void Print(int** arr, const int rowCount, const int colCount);
int Min(int** arr, const int size, int& index_min_h, int& index_min_v);
int Max(int** arr, const int size, int& index_max_h, int& index_max_v);
void Change(int** arr, const int size);
int Sum(int** arr, const int size);

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "n = "; cin >> n;

    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    Create(arr, n, n);
    Print(arr, n, n);

    int i1, i2;
    int max = Max(arr, n, i1, i2);
    cout << "Max[" << i1 << "][" << i2 << "] = " << max << endl;
    int min = Min(arr, n, i1, i2);
    cout << "Min[" << i1 << "][" << i2 << "] = " << min << endl;
    cout << "Sum = " << Sum(arr, n) << endl;
    Change(arr, n);

    Print(arr, n, n);

    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}

void Create(int** arr, const int colCount, const int rowCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            arr[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** arr, const int colCount, const int rowCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << arr[i][j];
        cout << endl;
    }
    cout << endl;
}

int Min(int** arr, const int size, int& index_min_h, int& index_min_v)
{
    index_min_h = 0;
    index_min_v = 0;
    for (int i = 0; i < size; i++)
    {
        for (int i1 = 0; i1 <= i; i1++)
        {
            if (arr[i][i1] < arr[index_min_h][index_min_v])
            {
                index_min_h = i;
                index_min_v = i1;
            }
        }
    }
    return arr[index_min_h][index_min_v];
}


int Max(int** arr, const int size, int& index_max_h, int& index_max_v)
{
    index_max_h = 0;
    index_max_v = 0;
    for (int i = 0; i < size; i++)
    {
        for (int i1 = i; i1 < size; i1++)
        {
            if (arr[i][i1] > arr[index_max_h][index_max_v])
            {
                index_max_h = i;
                index_max_v = i1;
            }
        }
    }
    return arr[index_max_h][index_max_v];
}

void Change(int** arr, const int size)
{
    int imh, imv;
    int imxh, imxv;

    Min(arr, size, imh, imv);
    Max(arr, size, imxh, imxv);

    auto tmp = arr[imh][imv];
    arr[imh][imv] = arr[imxh][imxv];
    arr[imxh][imxv] = tmp;
}

int Sum(int** arr, const int size)
{
    int i1, i2;
    return Min(arr, size, i1, i2) + Max(arr, size, i1, i2);
}