//template class
#include <iostream>
using namespace std;

template <class T>
class Node {
  T data;
  Node *next;

 public:
  Node() : data(T()), next(NULL) {}
  Node(T value) : data(value), next(NULL) {}

  ~Node() { delete next; }

  void setdata(T d) { data = d; }
  T getdata() { return data; }
  void setnext(Node *n) { next = n; }
  Node *getnext() { return next; }
};

template <class T>
class Stack {
  Node<T> *top;

 public:
  Stack() : top(NULL) {}
  
  ~Stack() {
    while (!isEmpty()) {
      pop();
    }
  }
  
  bool isEmpty() {
    return top == NULL;
  }

  void push(T x) {
    Node<T> *t = new Node<T>(x);
    if (t == NULL) {
      cout << "Stack overflow" << endl;
    } else {
      t->setnext(top);
      top = t;
    }
  }

  T pop() {
    if (isEmpty()) {
      cout << "Empty Stack" << endl;
      return T(); // Return default value of T
    } else {
      Node<T> *p = top;
      T x = top->getdata();
      top = top->getnext();
      delete p;
      return x;
    }
  }

  T peek(int index) {
    if (isEmpty()) {
      cout << "Empty Stack" << endl;
      return T();
    } else {
      Node<T> *p = top;
      for (int i = 0; p != NULL && i < index - 1; i++) {
        p = p->getnext();
      }
      if (p != NULL) {
        return p->getdata();
      } else {
        cout << "Index out of bounds" << endl;
        return T();
      }
    }
  }
};

int main() {
  Stack<float> s;
  s.push(10.5);
  s.push(20.5);
  s.push(30.5);

  cout << "Popped: " << s.pop() << endl;         // Should output 30.5
  cout << "Peek at index 2: " << s.peek(2) << endl;  // Should output 10.5

  return 0;
}
