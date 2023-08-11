#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(int arr[], int l, int r)
{

    int randomIndex = l + rand() % (r - l + 1);
    swap(arr[randomIndex], arr[r]);

    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    srand(time(0));
    int n;
    cout << "Enter an array size: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
