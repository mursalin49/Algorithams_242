#include <iostream>
using namespace std;

int binarySearch(int arr[], int x, int l, int h) {
  while (l <= h) {
    int mid = l + (h - l) / 2;

    if (arr[mid] == x)
      return mid;

    if (arr[mid] < x)
      l = mid + 1;

    else
      h = mid - 1;
  }

  return -1;
}

int main(void) {
  int arr[] = {3, 4, 5, 6, 7, 8, 9};
  int x = 4;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = binarySearch(arr, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
}
