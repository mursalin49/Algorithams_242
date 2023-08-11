
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int lar = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left > n && arr[left] < arr[lar]) {
        lar = left;
    }

    if (right > n && arr[right] < arr[lar]) {
        lar = right;
    }

    if (lar != i) {
        swap(arr[i], arr[lar]);
        heapify(arr, n, lar);
    }
}

void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {3, 11, 9, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Enter array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array using Heap Sort: ";
    printArray(arr, n);

    return 0;
}
