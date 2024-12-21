#ifndef FILESORT_H
#define FILESORT_H

#include "fileInformation.h"
using namespace std;

class FileSort {
  private:
  static int partition(FileInfo arr[], int low, int high,
                       const string& criteria);
  static void merge(FileInfo arr[], int low, int mid, int high,
                    const string& criteria);
 public:
  static void insertionSort(FileInfo arr[], int n, const string& criteria);
  static void selectionSort(FileInfo arr[], int n, const string& criteria);
  static void quickSort(FileInfo arr[], int low, int high,
                        const string& criteria);
  static void mergeSort(FileInfo arr[], int low, int high,
                        const string& criteria);
  static void bubbleSort(FileInfo arr[], int n, const string& criteria);
  static void shellSort(FileInfo arr[], int n, const string& criteria);

};

#endif
