#include <cstring>
#include <iostream>

#include "Notepad.h"

using namespace std;

void displayMenu() {
  cout << "\nWelcome to Notepad-like Word Processor!" << endl;
  cout << "1. Add text" << endl;
  cout << "2. Delete text" << endl;
  cout << "3. Undo last action" << endl;
  cout << "4. Display current text" << endl;
  cout << "5. Exit" << endl;
  cout << "Please select an option (1-5): ";
}

int main() {
  Notepad notepad(100, 0);  // Initialize Notepad with capacity 100 and cursor at position 0
  int choice;

  do {
    displayMenu();
    cin >> choice;

    // Clear the input buffer to prevent issues with getline
    cin.ignore();

    switch (choice) {
      case 1: {  // Add text
        string inputText;
        cout << "Enter text to add: ";
        getline(cin, inputText);
        notepad.addText(inputText.c_str());
        break;
      }

      case 2: {  // Delete text
        size_t length;
        cout << "Enter number of characters to delete: ";
        cin >> length;
        notepad.deleteText(length);
        break;
      }

      case 3: {  // Undo last action
        notepad.undo();
        break;
      }

      case 4: {  // Display current text
        notepad.displayText();
        break;
      }

      case 5: {  // Exit
        cout << "Exiting Notepad. Goodbye!" << endl;
        break;
      }

      default:
        cout << "Invalid choice. Please select a valid option (1-5)." << endl;
        break;
    }

  } while (choice != 5); 
  return 0;
}


