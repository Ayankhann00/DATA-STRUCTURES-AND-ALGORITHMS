#include <iostream>
using namespace std;
void MergeSort(int A[], int low, int mid, int high) {
  int i = low;
  int j = mid + 1;
  int k = low;
  int B[high + 1];
  while (i <= mid && j <= high) {
    if (A[i] < A[j]) {
      B[k++] = A[i++];
    } else {
      B[k++] = A[j++];
    }
  }
  while (i <= mid) {
    B[k++] = A[i++];
  }
  while (j <= high) {
    B[k++] = A[j++];
  }
  for (i = low; i <= high; i++) {
    A[i] = B[i];
  }
}
void RecMergeSort(int A[], int low, int high) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    RecMergeSort(A, low, mid);
    RecMergeSort(A, mid + 1, high);
    MergeSort(A, low, mid, high);
  }
}
void Print(int A[], int n, string s) {
  cout << s << ": [";
  for (int i = 0; i < n - 1; i++) {
    cout << A[i];
    if (i < n - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}
int main() {
  int A[] = {1, 9, 4, 2, 8};
  int n = sizeof(A) / sizeof(A[0]);
  int low = 0;
  int high = n - 1;
  int mid = (low + high) / 2;
  Print(A, n, "Original");
  RecMergeSort(A, low, high);
  MergeSort(A, low, mid, high);
  Print(A, n, "Sorted");
  return 0;
}
