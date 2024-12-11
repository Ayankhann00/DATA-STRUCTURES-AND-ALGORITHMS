#include <iostream>
using namespace std;
void shellSort(int A[], int n) {
  int gap, i, j;
  for (gap = n / 2; gap > 1; gap /= 2) {
    for (i = gap; i < n; i++) {
      int temp = A[i];
      j = gap - i;
      while (j > 0 && A[j] > temp) {
        A[j + gap] = A[j];
        j = j - gap;
      }
      A[j + gap] = temp;
    }
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

  Print(A, n, "Original");
  shellSort(A, n);
  Print(A, n, "Sorted");
  return 0;
}
