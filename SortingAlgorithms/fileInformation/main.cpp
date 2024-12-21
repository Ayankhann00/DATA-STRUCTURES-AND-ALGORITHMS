#include <chrono>
#include <filesystem>
#include <iostream>

#include "fileInformation.h"
#include "fileSort.h"

namespace fs = std::filesystem;
using namespace std;

const int MAX_FILES = 500;

string timeToString(fs::file_time_type ftime) {
  auto sctp = chrono::time_point_cast<chrono::system_clock::duration>(
      ftime - fs::file_time_type::clock::now() + chrono::system_clock::now());
  time_t t = chrono::system_clock::to_time_t(sctp);
  return ctime(&t);
}

int main() {
  FileInfo files[MAX_FILES];
  int count = 0;

  string directoryPath = "/Users/ayaanhassan/Downloads";
  for (const auto& entry : fs::directory_iterator(directoryPath)) {
    if (fs::is_regular_file(entry) && count < MAX_FILES) {
      files[count++] =
          FileInfo(entry.path().filename().string(), fs::file_size(entry),
                   timeToString(fs::last_write_time(entry)));
    }
  }

  cout << "Total files read: " << count << "\n";

  cout << "\nChoose sorting criteria (name/size/date): ";
  string criteria;
  cin >> criteria;

  cout << "Choose sorting algorithm:\n1. Insertion Sort\n2. Selection Sort\n3. "
          "Quick Sort\n4. Merge Sort\n5. Bubble Sort\n6. Shell Sort\n";
  int choice;
  cin >> choice;

  auto start = chrono::high_resolution_clock::now();
  switch (choice) {
    case 1:
      FileSort::insertionSort(files, count, criteria);
      break;
    case 2:
      FileSort::selectionSort(files, count, criteria);
      break;
    case 3:
      FileSort::quickSort(files, 0, count - 1, criteria);
      break;
    case 4:
      FileSort::mergeSort(files, 0, count - 1, criteria);
      break;
    case 5:
      FileSort::bubbleSort(files, count, criteria);
      break;
    case 6:
      FileSort::shellSort(files, count, criteria);
      break;
    default:
      cout << "Invalid choice! Exiting program.\n";
      return 1;
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

  cout << "Sorted files:" << endl;
  for (int i = 0; i < count; i++) {
    files[i].displayInfo();
  }

  cout << "Sorting took " << duration.count() << " milliseconds." << endl;
  return 0;
}
