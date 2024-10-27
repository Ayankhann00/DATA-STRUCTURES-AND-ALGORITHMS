//Queues In DSA
#include <iostream>
using namespace std;
class Queue {
    int size;
    int front;
    int rear;
    int* A;
public:
    Queue(int size);
    ~Queue();
    void Enqueue(int d);
    int Dequeue();
    bool isEmpty();
    bool isFull();
    void Display();
};

// Constructor
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    A = new int[size];
}

// Destructor
Queue::~Queue() {
    delete[] A;
}

// Check if the queue is empty
bool Queue::isEmpty() {
    return (front == rear);
}

// Check if the queue is full
bool Queue::isFull() {
    return (rear == size - 1);
}

// Enqueue operation
void Queue::Enqueue(int d) {
    if (isFull()) {
        cout << "Queue Overflow" << endl;
    } else {
        rear++;
        A[rear] = d;
    }
}

// Dequeue operation
int Queue::Dequeue() {
    int d = -1;
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        d = A[front];
    }
    return d;
}

// Display the elements in the queue
void Queue::Display() {
    for (int i = front + 1; i <= rear; i++) {
        cout << A[i] << flush;
        if (i < rear) {
            cout << " <- " << flush;
        }
    }
    cout << endl;
}

int main() {
    int A[] = {1, 5, 9, 4, 3};
    Queue q(5);

    // Enqueue elements from array
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        q.Enqueue(A[i]);
    }
    q.Display();

    // Try enqueueing one more element to see overflow
    q.Enqueue(10);

    // Dequeue all elements
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
        q.Dequeue();
    }

    // Dequeue from empty queue to see underflow
    q.Dequeue();
    q.Display();

    return 0;
}
