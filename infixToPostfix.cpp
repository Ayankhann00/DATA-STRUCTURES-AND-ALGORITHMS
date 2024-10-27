#include <cstring>
#include <iostream>
using namespace std;

class Stack {
  int s;             // size of the stack
  int top;           // top of the stack
  char *stackArray;  // array for storing characters
 public:
  Stack(int size);
  ~Stack();
  void push(char n);
  char pop();
  bool isEmpty();
  bool isFull();
  bool isOperand(char x);
  int precedence(char x);
  char *infixToPostfix(char *infix);
};

Stack::Stack(int size) {
  s = size;
  top = -1;                  // starting from -1 index
  stackArray = new char[s];  // create a dynamic array for the stack
}

Stack::~Stack() {
  delete[] stackArray;  // destructor to deallocate the memory
}

void Stack::push(char n) {
  if (!isFull()) {
    stackArray[++top] = n;  // assign the top index to the element n
  } else {
    cout << "Stack overflow" << endl;
  }
}

char Stack::pop() {
  if (!isEmpty()) {
    return stackArray[top--];
  } else {
    cout << "Stack underflow" << endl;
    return -1;
  }
}

bool Stack::isEmpty() { return (top == -1); }

bool Stack::isFull() { return (top == s - 1); }

bool Stack::isOperand(char x) {
  return !(x == '+' || x == '-' || x == '*' || x == '/' || x == '^' ||
           x == '(' || x == ')');
}

int Stack::precedence(char x) {
  if (x == '+' || x == '-') return 1;
  if (x == '*' || x == '/') return 2;
  if (x == '^') return 3;  // Right-associative
  return 0;
}

// Function to convert infix to postfix
char *Stack::infixToPostfix(char *infix) {
  int len = strlen(infix);
  char *postfix = new char[len + 1];
  int i = 0, j = 0;

  while (infix[i] != '\0') {
    if (isOperand(infix[i])) {
      postfix[j++] = infix[i++];
    } else if (infix[i] == '(') {
      push(infix[i++]);
    } else if (infix[i] == ')') {
      while (!isEmpty() && stackArray[top] != '(') {
        postfix[j++] = pop();
      }
      pop();  // Remove '(' from stack
      i++;
    } else {
      while (!isEmpty() &&
             precedence(stackArray[top]) >= precedence(infix[i])) {
        if (infix[i] == '^' && stackArray[top] == '^')
          break;  // Right-associativity for '^'
        postfix[j++] = pop();
      }
      push(infix[i++]);
    }
  }

  // Pop remaining operators in stack
  while (!isEmpty()) {
    postfix[j++] = pop();
  }
  postfix[j] = '\0';
  return postfix;
}

int main() {
  char infix[] = "a+b*c-d/e";
  Stack s1(20);
  char *postfix = s1.infixToPostfix(infix);
  cout << "Postfix Expression: " << postfix << endl;

  delete[] postfix;  // Clean up allocated memory for postfix
  return 0;
}
