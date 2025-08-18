#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n)
{
    if (n == 1)
        return;

    for (int j = 0; j <= n - 2; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1])
        }
    }
    bubbleSort(arr, n--);
}