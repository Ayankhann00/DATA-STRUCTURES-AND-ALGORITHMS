#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int partition(int A[], int l, int h) {
  int pivot = A[l];
  int i = l, j = h;

  do {
    do {
      i++;
    } while (A[i] <= pivot && i < h);

    do {
      j--;
    } while (A[j] > pivot);

    if (i < j) {
      swap(A[i], A[j]);
    }
  } while (i < j);

  swap(A[l], A[j]);
  return j;
}

void QuickSort(int A[], int l, int h) {
  if (l < h) {
    int j = partition(A, l, h);
    QuickSort(A, l, j);
    QuickSort(A, j + 1, h);
  }
}

void Print(int A[], int n, string s) {
  cout << s << ": [";
  for (int i = 0; i < n - 1; i++) {
    cout << A[i];
    if (i < n - 2) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int main() {
  int A[] = {1, 9, 4, 2, 8, INT_MAX};
  int n = sizeof(A) / sizeof(A[0]);

  QuickSort(A, 0, n - 1);
  Print(A, n, "Sorted Array");

  cout << "The sorted array is" << endl;
  for (int i = 0; i < n - 1; i++) {
    cout << A[i] << " ";
  }

  return 0;
}
