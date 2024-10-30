// Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
// A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
// If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

// Implement the MyLinkedList class:

// MyLinkedList() Initializes the MyLinkedList object.
// int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
// void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
// void addAtTail(int val) Append a node of value val as the last element of the linked list.
// void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
// void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int value)
    {
        val = value;
        next = nullptr;
    }
};

class MyLinkedList
{
public:
    Node *head;

    MyLinkedList()
    {
        head = nullptr;
    }

    int get(int index)
    {
        Node *current = head;
        int count = 0;
        while (current != nullptr)
        {
            if (count == index)
            {
                return current->val;
            }
            count++;
            current = current->next;
        }
        return -1; // If index is out of bounds
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;

        for (int i = 0; i < index - 1; i++)
        {
            if (temp == nullptr)
            {
                cout << "Index is out of range" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp != nullptr)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
        else
        {
            cout << "Index is out of range" << endl;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || head == nullptr)
        {
            cout << "Invalid index" << endl;
            return;
        }

        if (index == 0)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            if (temp == nullptr || temp->next == nullptr)
            {
                cout << "Index is out of range" << endl;
                return;
            }
            temp = temp->next;
        }

        Node *toDelete = temp->next;
        if (toDelete != nullptr)
        {
            temp->next = toDelete->next;
            delete toDelete;
        }
        else
        {
            cout << "Index is out of range" << endl;
        }
    }

    void countList()
    {
        int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        cout << "Number of elements in the list is " << count << endl;
    }

    void printList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main()
{
    MyLinkedList list;

    list.addAtHead(10);
    list.addAtHead(20);
    list.addAtHead(30);
    list.addAtTail(50);
    list.addAtTail(60);
    list.addAtIndex(2, 55);
    list.deleteAtIndex(3);

    list.countList();
    list.printList();

    return 0;
}
