#include <iostream>
using namespace std;
template <class T>
class BubbleSort {
  int *arr;
  int n;

 public:
  BubbleSort() { arr = new int[n]; }
  void swap(T *x, T *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
  }
  void sort(T arr[], T n) {
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++) {
        if (arr[j] > arr[j + 1]) {
          swap(&arr[j], &arr[j + 1]);
          flag = 1;
        }
        if (flag == 0) {
          return;
        }
      }
    }
  }
  void Print(T arr[], int n, string s) {
    cout << s << ": [";
    for (int i = 0; i < n; i++) {
      cout << arr[i];
      if (i < n - 1) {
        cout << ", ";
      }
    }
    cout << "]" << endl;
  }
};
int main() {
  int arr[] = {5, 3, 6, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  BubbleSort<int> b;  // Create an instance of BubbleSort for integers
  b.Print(arr, n, "Unsorted Array");  // Print the unsorted array
  b.sort(arr, n);                     // Sort the array
  b.Print(arr, n, "Sorted Array");    // Print the sorted array
  return 0;
}
