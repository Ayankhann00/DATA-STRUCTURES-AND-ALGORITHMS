#include "fileInformation.h"

#include <iostream>
using namespace std;

// Constructor
FileInfo::FileInfo(const string& name, size_t size, const string& date)
    : fileName(name), fileSize(size), lastModified(date) {}

// Display function
void FileInfo::displayInfo() const {
  cout << "Name: " << fileName << ", Size: " << fileSize
       << " bytes, Date: " << lastModified << endl;
}
