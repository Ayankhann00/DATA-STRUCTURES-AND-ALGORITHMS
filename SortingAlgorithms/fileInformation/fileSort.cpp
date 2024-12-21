#include "fileSort.h"

#include <algorithm>
#include <iostream>
using namespace std;

// Helper comparison functions
bool compareByName(const FileInfo& a, const FileInfo& b) {
  return a.fileName < b.fileName;
}

bool compareBySize(const FileInfo& a, const FileInfo& b) {
  return a.fileSize < b.fileSize;
}

bool compareByDate(const FileInfo& a, const FileInfo& b) {
  return a.lastModified < b.lastModified;
}

// Insertion Sort
void FileSort::insertionSort(FileInfo arr[], int n, const string& criteria) {
  for (int i = 1; i < n; i++) {
    FileInfo key = arr[i];
    int j = i - 1;

    while (j >= 0 &&
           ((criteria == "name" && arr[j].fileName > key.fileName) ||
            (criteria == "size" && arr[j].fileSize > key.fileSize) ||
            (criteria == "date" && arr[j].lastModified > key.lastModified))) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

// Selection Sort
void FileSort::selectionSort(FileInfo arr[], int n, const string& criteria) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if ((criteria == "name" && arr[j].fileName < arr[minIndex].fileName) ||
          (criteria == "size" && arr[j].fileSize < arr[minIndex].fileSize) ||
          (criteria == "date" &&
           arr[j].lastModified < arr[minIndex].lastModified)) {
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
  }
}

// Quick Sort
int FileSort::partition(FileInfo arr[], int low, int high,
                        const string& criteria) {
  FileInfo pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if ((criteria == "name" && arr[j].fileName <= pivot.fileName) ||
        (criteria == "size" && arr[j].fileSize <= pivot.fileSize) ||
        (criteria == "date" && arr[j].lastModified <= pivot.lastModified)) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void FileSort::quickSort(FileInfo arr[], int low, int high,
                         const string& criteria) {
  if (low < high) {
    int pi = partition(arr, low, high, criteria);
    quickSort(arr, low, pi - 1, criteria);
    quickSort(arr, pi + 1, high, criteria);
  }
}

// Merge Sort
void FileSort::merge(FileInfo arr[], int low, int mid, int high,
                     const string& criteria) {
  int n1 = mid - low + 1;
  int n2 = high - mid;

  FileInfo* L = new FileInfo[n1];
  FileInfo* R = new FileInfo[n2];

  for (int i = 0; i < n1; i++) L[i] = arr[low + i];
  for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

  int i = 0, j = 0, k = low;

  while (i < n1 && j < n2) {
    if ((criteria == "name" && L[i].fileName <= R[j].fileName) ||
        (criteria == "size" && L[i].fileSize <= R[j].fileSize) ||
        (criteria == "date" && L[i].lastModified <= R[j].lastModified)) {
      arr[k++] = L[i++];
    } else {
      arr[k++] = R[j++];
    }
  }

  while (i < n1) arr[k++] = L[i++];
  while (j < n2) arr[k++] = R[j++];

  delete[] L;
  delete[] R;
}

void FileSort::mergeSort(FileInfo arr[], int low, int high,
                         const string& criteria) {
  if (low < high) {
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid, criteria);
    mergeSort(arr, mid + 1, high, criteria);
    merge(arr, low, mid, high, criteria);
  }
}

// Bubble Sort
void FileSort::bubbleSort(FileInfo arr[], int n, const string& criteria) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if ((criteria == "name" && arr[j].fileName > arr[j + 1].fileName) ||
          (criteria == "size" && arr[j].fileSize > arr[j + 1].fileSize) ||
          (criteria == "date" &&
           arr[j].lastModified > arr[j + 1].lastModified)) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

// Shell Sort
void FileSort::shellSort(FileInfo arr[], int n, const string& criteria) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      FileInfo temp = arr[i];
      int j;
      for (j = i;
           j >= gap &&
           ((criteria == "name" && arr[j - gap].fileName > temp.fileName) ||
            (criteria == "size" && arr[j - gap].fileSize > temp.fileSize) ||
            (criteria == "date" &&
             arr[j - gap].lastModified > temp.lastModified));
           j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}
