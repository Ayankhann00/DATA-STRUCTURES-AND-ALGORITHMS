#include "Notepad.h"

#include <cstring>
#include <iostream>
using namespace std;

// textStack Implementation
template <typename T>
textStack<T>::textStack() : topNode(nullptr) {
  // Constructor initializes an empty stack
}

template <typename T>
textStack<T>::~textStack() {
  // Destructor to clean up the stack
  while (!isEmpty()) {
    pop();
  }
}

template <typename T>
void textStack<T>::setNext(Node* n) {
  if (topNode) {
    topNode->next = n;
  }
}

template <typename T>
typename textStack<T>::Node* textStack<T>::getNext() {
  return topNode ? topNode->next : nullptr;
}

template <typename T>
void textStack<T>::push(const T& cmd) {
  // Use explicit Node constructor
  Node* newNode = new Node(cmd, topNode);
  topNode = newNode;
}

template <typename T>
void textStack<T>::pop() {
  if (isEmpty()) return;
  Node* temp = topNode;
  topNode = topNode->next;
  delete temp;
}

template <typename T>
const T& textStack<T>::top() const {
  if (isEmpty()) throw runtime_error("Stack is empty.");
  return topNode->data;
}

template <typename T>
bool textStack<T>::isEmpty() const {
  return topNode == nullptr;
}

// Notepad Implementation
Notepad::Notepad(size_t capacity, size_t cursorPos)
    : capacity(capacity), cursorPosition(cursorPos), text(nullptr) {
  text = new char[capacity];
  text[0] = '\0';  // Ensure the text starts empty
}

Notepad::~Notepad() { delete[] text; }

void Notepad::addText(const char* inputText) {
  size_t inputLen = strlen(inputText);

  // Expand the buffer if needed
  if (cursorPosition + inputLen > capacity) {
    expandText((cursorPosition + inputLen) * 2);  // Double the capacity
  }

  // Shift existing text to make room for new input
  size_t textLen = strlen(text);
  for (int i = textLen; i >= static_cast<int>(cursorPosition); --i) {
    text[i + inputLen] = text[i];
  }

  // Insert the new text
  for (size_t i = 0; i < inputLen; ++i) {
    text[cursorPosition + i] = inputText[i];
  }

  // Update cursor position
  cursorPosition += inputLen;

  // Push the ADD operation onto the undo stack
  Command addCommand(Command::ADD, inputText, cursorPosition - inputLen);
  undoStack.push(addCommand);
}

void Notepad::deleteText(size_t length) {
  if (cursorPosition == 0) {
    cout << "No text to delete.\n";
    return;
  }

  // Adjust the length if it exceeds available characters before the cursor
  if (length > cursorPosition) {
    length = cursorPosition;
  }

  // Store the text to be deleted
  char* delText = new char[length + 1];
  strncpy(delText, text + cursorPosition - length, length);
  delText[length] = '\0';

  // Shift the text to the left
  size_t textLen = strlen(text);
  for (size_t i = cursorPosition; i <= textLen; ++i) {
    text[i - length] = text[i];
  }

  // Update the cursor position
  cursorPosition -= length;

  // Push the DELETE operation onto the undo stack
  Command deleteCommand(Command::DELETE, delText, cursorPosition);
  undoStack.push(deleteCommand);

  delete[] delText;
}

void Notepad::undo() {
  if (undoStack.isEmpty()) {
    cout << "Nothing to undo.\n";
    return;
  }

  Command command = undoStack.top();
  undoStack.pop();

  switch (command.op) {
    case Command::ADD:
      cursorPosition = command.cursorPosition;
      deleteText(strlen(command.text));
      break;

    case Command::DELETE:
      cursorPosition = command.cursorPosition;
      size_t textLen = strlen(command.text);

      if (cursorPosition + textLen > capacity) {
        expandText((cursorPosition + textLen) * 2);
      }

      for (int i = strlen(text); i >= static_cast<int>(cursorPosition); --i) {
        text[i + textLen] = text[i];
      }

      for (size_t i = 0; i < textLen; ++i) {
        text[cursorPosition + i] = command.text[i];
      }

      cursorPosition += textLen;
      break;
  }
}

void Notepad::expandText(size_t newCapacity) {
  if (newCapacity <= capacity) return;  // Avoid unnecessary expansion
  char* newText = new char[newCapacity];
  strcpy(newText, text);
  delete[] text;
  text = newText;
  capacity = newCapacity;
}

void Notepad::displayText() const {
  if (text[0] == '\0') {
    cout << "Nothing to display.\n";
  } else {
    cout << text << endl;
    for (size_t i = 0; i < cursorPosition; ++i) {
      cout << " ";
    }
    cout << "^ (Cursor)" << endl;
  }
}

void Notepad::moveCursor(int direction) {
  int newPosition = cursorPosition + direction;

  if (newPosition < 0) {
    cursorPosition = 0;
  } else if (newPosition > strlen(text)) {
    cursorPosition = strlen(text);
  } else {
    cursorPosition = newPosition;
  }
  cout << "Cursor moved to position: " << cursorPosition << endl;
}
