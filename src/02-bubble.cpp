#include <iostream>
using namespace std;

void bubbleSort(int *arr, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int a[] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5};
    int len = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, len);
    for (int i = 0; i < len; i++)
    {
        cout << a[i] << endl;
    }
    system("pause");
    return 0;
}