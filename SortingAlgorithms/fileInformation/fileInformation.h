#ifndef FILEINFORMATION_H
#define FILEINFORMATION_H

#include <string>
using namespace std;
class FileInfo {
 public:
  string fileName;
  size_t fileSize;
  string lastModified;

  FileInfo(const string& name = "", size_t size = 0,
           const string& date = "");
  void displayInfo() const;
};

#endif
