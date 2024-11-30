template <class T>
class InsertionSort {
  int *arr;
  int n;

 public:
  InsertionSort() { arr = new int[n]; }
  void sort(T arr[], T n) {
    for (int i = 1; i < n; i++) {
      int j = i - 1;
      int x = arr[i];
      while (j > -1 && arr[j] > x) {
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = x;
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
