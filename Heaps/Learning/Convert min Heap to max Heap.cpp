// User function Template for C++

class Solution
{
public:
    void heapify(vector<int> &arr, int n, int i)
    {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = 0;
        if (l < n && arr[l] > arr[i])
            largest = l;
        else
            largest = i;
        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }
};

