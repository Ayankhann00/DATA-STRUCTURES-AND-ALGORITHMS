template <class T>
class SelectionSort {
  int *arr;
  int n;

 public:
  SelectionSort() { arr = new int[n]; }
  void swap(T *x, T *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
  }
  void sort(T arr[], T n) {
    for (int i = 0; i < n - 1; i++) {
      int j, k;
      for (j = k = i; j < n; j++) {
        if (arr[j] < arr[k]) k = j;
      }
      swap(&arr[i], &arr[k]);
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
