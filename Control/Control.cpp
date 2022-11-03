#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

const int n(10);
const int sz = 18;

void ArrayOne(int arr[], int half);
void ArrayTwo(int arr[], int half);
void One(int arr[], int sz, int half);
void Two(int arr[], int half);
void sum(int* op1, int* op2, int* res, int n);


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    /*1
    int arr[n];
    cout << "Ваш массив: ";
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 5;
        cout << arr[i] << " ";
    }
    cout << "Наоборот: ";
    for (int i = n - 1; i >= 0; --i)cout << arr[i] << " ";


    2
    int s = 0, a[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Сторона: " << i + 1 << " = ";
        cin >> a[i];
        s += a[i];
    }
    cout << "Периметр: " << s;
    3
    int myArray[sz];
    float num = 0.0;
    float res = 0.0;
    int half = 0;

    cout << "Среднее значение = ";
    cin >> num;

    srand(time(NULL));
    half = (sz / 3) * 2;

    for (int i = 0; i < sz; i++)
    {
        myArray[i] = rand() % 100 + 1;
    }

    cout << "\nМассив : \n\n";
    for (int i = 0; i < sz; i++)
    {
        if (i == 12)
        {
            cout << " |";
        }
        cout << " " << myArray[i];
    }

    for (int i = 0; i < half; i++)
    {
        res += myArray[i];
        if (i == half - 1)
        {
            res = res / i;
        }
    }


    if (res > num)
    {
        cout << "\n\n1";
        ArrayOne(myArray, half);
    }
    if (res < num)
    {
        cout << "\n\n2";
        ArrayTwo(myArray, half);
    }


    cout << "\n\nСортированный массив : \n\n";
    for (int i = 0; i < sz; i++)
    {
        if (i == 12)
        {
            cout << " |";
        }
        cout << " " << myArray[i];
    }

    cout << "\n\n";
    4
    int a[n] = { 1,7,3,5,2,4,6,7,9,3 }, s = 0;
    for (int i = 0; i < 10; i++)cout << setw(3) << *(a + i);
    cout << endl;
    for (int i = 0; i < 10; i++)s += *(a + i);
    cout << s << endl;
    5
    int a1[] = { 1,4,12,-3 };
    int a2[] = { 11,4,-75,1 };
    int a3[4];
    sum(a1, a2, a3, 4);
    for (int i = 0; i < 4; i++)cout << a3[i] << " ";
    cout << endl;*/
}

void sum(int* op1, int* op2, int* res, int n)
{
    *res = (*op1) + (*op2);
    --n;
    if (n > 0) sum(++op1, ++op2, ++res, n);
}

void ArrayOne(int arr[], int half)
{
    int t = 0;

    for (int i = 0; i < half - 1; i++)
    {
        if (i == half - 2)
        {
            One(arr, sz, half);
        }
        for (int j = i + 1; j < half; j++)
        {
            if (arr[i] > arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

void ArrayTwo(int arr[], int half)
{
    int t = 0;
    Two(arr, half);

    for (int i = half; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (arr[i] > arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

void One(int arr[], int sz, int half)
{
    int t = 0;

    for (int i = half; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (arr[i] < arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}

void Two(int arr[], int half)
{
    int t = 0;

    for (int i = 0; i < half - 1; i++)
    {
        for (int j = i + 1; j < half; j++)
        {
            if (arr[i] < arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
        }
    }
}