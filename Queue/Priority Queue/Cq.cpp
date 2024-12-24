#include "Cq.h"

#include <iostream>
using namespace std;

Cqueue::Cqueue(int size) {
  this->size = size;
  front = -1;
  rear = -1;
  Q = new int[size];
}
Cqueue::~Cqueue() { delete[] Q; }
bool Cqueue::isEmpty() {
  if (front == rear) {
    return true;
  } else {
    return false;
  }
}
bool Cqueue::isFull() {
  if ((rear + 1) % size == front) {
    return true;
  } else {
    return false;
  }
}
void Cqueue::enqueue(int x) {
  if (isFull()) {
    cout << "Queue is full" << endl;
  } else {
    rear = (rear + 1) % size;
    x = Q[rear];
  }
}
int Cqueue::dequeue() {
  int x = -1;
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
  } else {
    front = (front + 1) % size;
    Q[front] = x;
  }
  return x;
}
void Cqueue::Display() {
  int i = front + 1;
  do {
    cout << Q[i] << flush;
    if (i < rear) {
      cout << "<-" << flush;
    }
    i = (i + 1) % size;
  } while (i != (rear + 1) % size);
}