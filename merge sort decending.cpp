#include <iostream>
using namespace std;
void merge(int arr[], int l, int mid, int r)
{
    int b[r - l + 1];
    int l1 = l, l2 = mid + 1, i = 0;
    while (l1 <= mid && l2 <= r)
    {
        if (arr[l1] >= arr[l2])
            b[i++] = arr[l1++];
        else
            b[i++] = arr[l2++];
    } // end while loop here
    while (l1 <= mid)
    {
        b[i++] = arr[l1++];
    }

    while (l2 <= r)
    {
        b[i++] = arr[l2++];
    }

    int j = 0;
    for (i = l; i <= r; i++)
        arr[i] = b[j++];
}

void mergeSort(int arr[], int l, int r)
{
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}


int main()
{
    int i = 0;
    int arr[] = {14, 12, 1, 20, 20, 40, 60, 80, 85, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int l = 0, r = size - 1;
    mergeSort(arr, l, r);
    for (i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
