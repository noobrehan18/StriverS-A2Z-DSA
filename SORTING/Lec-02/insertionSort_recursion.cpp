void insertionSort(vector<int> arr, int i, int n)
{
    if (i == n)
        return;
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        swap(arr[j - 1], arr[j]);
        j--;
    }
    insertionSort(arr, i++, n);
}