#include <cstring>
#include <iostream>
using namespace std;

class Stack {
  int s;    // size of the array
  int top;  // top of the stack
  char *a;  // pointer to create a dynamic array for integers
 public:
  Stack(int s);
  ~Stack();
  // operations on stack
  void push(char n);
  int pop();
  bool isEmpty();
  bool isFull();
  void Clear();
  void Peak();
  void display();
};

Stack::Stack(int s) {
  this->s = s;
  top = -1;         // starting from -1 index
  a = new char[s];  // create a dynamic array for the stack
}

Stack::~Stack() {
  delete[] a;  // destructor to deallocate the memory
}

void Stack::push(char n) {
  if (!isFull()) {
    top++;       // increment the top index
    a[top] = n;  // assign the address of the top pointer to element n
  } else {
    cout << "Stack overflow" << endl;
  }
}

int Stack::pop() {
  if (!isEmpty()) {
    int n = a[top];  // updating the top value of the stack after popping out a
                     // value
    top--;
    return n;
  } else {
    cout << "Stack underflow" << endl;
    return -1;  // return -1 as an error code if the stack is empty
  }
}

bool Stack::isEmpty() { return (top == -1); }

bool Stack::isFull() { return (top == s - 1); }

void Stack::Clear() {
  top = -1;  // reset the stack
}

void Stack::Peak() {  // return the top value of the stack if the stack is not
                      // empty
  if (!isEmpty()) {
    cout << a[top] << endl;
  } else {
    cout << "Stack Underflow" << endl;
  }
}

void Stack::display() {
  for (int i = top; i >= 0;
       i--) {  // displays the elements of the array in the stack
    cout << a[i] << " | " << flush;
  }
  cout << endl;
}

// Function to check if the integer sequence is balanced
bool isBalanced(char *exp) {
  Stack stk(
      strlen(exp));  // create a stack with size equal to expression length

  for (int i = 0; exp[i] != '\0'; i++) {
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      stk.push(exp[i]);  // push opening brackets onto the stack
    } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
      if (stk.isEmpty()) {
        return false;  // if stack is empty, return false (unmatched closing
                       // bracket)
      }
      char top = stk.pop();  // pop the top element from the stack

      // Check if the popped bracket matches the closing bracket
      if ((exp[i] == ')' && top != '(') || (exp[i] == '}' && top != '{') ||
          (exp[i] == ']' && top != '[')) {
        return false;  // Mismatch found
      }
    }
  }

  // If the stack is empty, parentheses are balanced, otherwise they are not
  return stk.isEmpty();
}

int main() {
  char exp[] = "1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10) – 11 + (12*8)] + 14";
  int length = sizeof(exp) / sizeof(exp[0]);  // get the length of the array

  if (isBalanced(exp)) {
    cout << "The expression is correct." << endl;
  } else {
    cout << "The expression is not correct." << endl;
  }

  return 0;
}
