#include <iostream>
using namespace std;
int search(int arr[], int n, int x) {
  for (int i = 0; i < n; i++)
    if (arr[i] == x)
      return i;
  return -1;
}
int main() {
  int arr[] = {2, 4, 0, 1, 9};
  int x = 1;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = search(arr, n, x);
  (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;
}
