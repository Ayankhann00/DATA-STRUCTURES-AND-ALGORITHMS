#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <cstring>
#include <iostream>
using namespace std;

// Command struct for undo functionality
struct Command {
  enum Operation { ADD, DELETE };
  Operation op;
  char* text;
  size_t cursorPosition;

  Command(Operation operation, const char* t, size_t position)
      : op(operation), cursorPosition(position) {
    text = new char[strlen(t) + 1];
    strcpy(text, t);
  }

  Command(const Command& other)
      : op(other.op), cursorPosition(other.cursorPosition) {
    text = new char[strlen(other.text) + 1];
    strcpy(text, other.text);
  }

  Command& operator=(const Command& other) {
    if (this != &other) {
      delete[] text;
      text = new char[strlen(other.text) + 1];
      strcpy(text, other.text);
      op = other.op;
      cursorPosition = other.cursorPosition;
    }
    return *this;
  }

  ~Command() { delete[] text; }
};

// Custom Stack class
template <typename T>
class textStack {
 private:
  struct Node {
    T data;
    Node* next;

    // Constructor for Node
    Node(const T& cmd, Node* nextNode = nullptr) : data(cmd), next(nextNode) {}
  };

  Node* topNode;  // Pointer to the top of the stack

 public:
  textStack();              // Constructor
  ~textStack();             // Destructor
  void setNext(Node* n);    // Set the next pointer of the top node
  Node* getNext();          // Get the next pointer of the top node
  void push(const T& cmd);  // Pushes an element onto the stack
  void pop();               // Removes the top element
  const T& top() const;     // Returns the top element
  bool isEmpty() const;     // Checks if the stack is empty
};

// Notepad class
class Notepad {
 private:
  char* text;                    // Character array to hold the current text
  size_t capacity;               // Capacity of the character array
  size_t cursorPosition;         // Cursor position in the text
  textStack<Command> undoStack;  // Custom stack for undo commands

  void expandText(size_t newCapacity);  // Expands the character array

 public:
  Notepad(size_t capacity = 100, size_t cursorPos = 0);  // Constructor
  ~Notepad();                                            // Destructor
  void addText(const char* inputText);                   // Adds text
  void deleteText(size_t length);                        // Deletes text
  void undo();                                           // Undo the last action
  void displayText() const;                              // Displays the text
  void moveCursor(int direction);                        // Moves the cursor
};

#endif
