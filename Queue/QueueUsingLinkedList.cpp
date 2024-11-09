#include <iostream>
using namespace std;

class Node {
    int data;
    Node* next;

public:
    Node(int value) {
        data = value;
        next = NULL;
    }
    
    ~Node() {
        delete next; // recursive delete
    }
    
    void setData(int value) {
        data = value;
    }
    
    int getData() {
        return data;
    }
    
    void setNext(Node* nextNode) {
        next = nextNode;
    }
    
    Node* getNext() {
        return next;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    ~Queue() {
        while (front != NULL) {
            Node* temp = front;
            front = front->getNext();
            temp->setNext(NULL); // prevent recursive delete
            delete temp;
        }
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (newNode == NULL) {
            cout << "Queue overflow" << endl;
            return;
        }
        
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->setNext(newNode);
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        
        Node* temp = front;
        int value = front->getData();
        front = front->getNext();
        
        if (front == NULL) { // queue is empty after dequeue
            rear = NULL;
        }
        
        temp->setNext(NULL); // prevent recursive delete
        delete temp;
        
        return value;
    }

    void displayQueue() {
        Node* p = front;
        while (p != NULL) {
            cout << p->getData();
            p = p->getNext();
            if (p != NULL) {
                cout << " <- ";
            }
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue after enqueues: ";
    q.displayQueue();

    cout << "Dequeue: " << q.dequeue() << endl;

    cout << "Queue after dequeue: ";
    q.displayQueue();

    return 0;
}
