// Circular Doubly Linked List
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next; // pointer for the next node
    Node *prev; // pointer to the prev node

    Node(int value) // constructor
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class Create
{
public:
    Node *head;

    Create()
    {
        head = nullptr;
    }

    void addHead(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            Node *tail = head->prev; // logic to add before head by first making tail's next point to the new node.
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }
    }

    void addTail(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            newNode->next = newNode;
            newNode->prev = newNode;
        }
        else
        {
            Node *tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
        }
    }

    void insertAtLocation(int location, int value)
    {
        if (location < 1)
        {
            cout << "Invalid location" << endl;
            return;
        }

        if (location == 1)
        {
            addHead(value);
            return;
        }

        Node *temp = head;
        for (int i = 1; i < location - 1; i++) // traversing through the loop to reach the position
        {
            temp = temp->next;
            if (temp == head)
            {
                cout << "Invalid location" << endl;
                return;
            }
        }

        Node *newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteHead()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *tail = head->prev;
        Node *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }

    void del(int location)
    {
        if (location < 1)
        {
            cout << "Invalid location" << endl;
            return;
        }
        if (location == 1)
        {
            deleteHead();
            return;
        }

        Node *temp = head;
        for (int i = 1; i < location - 1; i++)
        {
            temp = temp->next;
            if (temp->next == head)
            {
                cout << "Invalid location" << endl;
                return;
            }
        }

        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        nodeToDelete->next->prev = temp;

        delete nodeToDelete;
    }

    void printList()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }
};

// menu function to creat a circular doubly linked list
int main()
{
    int choice;
    Create c1;

    do
    {
        cout << "\nChoose the operations on circular doubly linked list:" << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at tail" << endl;
        cout << "3. Insert at certain location" << endl;
        cout << "4. Delete head" << endl;
        cout << "5. Delete a node at any location" << endl;
        cout << "6. Print the linked list" << endl;
        cout << "7. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the value: ";
            int value;
            cin >> value;
            c1.addHead(value);
            break;
        }
        case 2:
        {
            cout << "Enter the value: ";
            int value;
            cin >> value;
            c1.addTail(value);
            break;
        }
        case 3:
        {
            cout << "Enter the value and position: ";
            int value, position;
            cin >> value >> position;
            c1.insertAtLocation(position, value);
            break;
        }
        case 4:
        {
            c1.deleteHead();
            break;
        }
        case 5:
        {
            cout << "Enter the position to be deleted: ";
            int position;
            cin >> position;
            c1.del(position);
            break;
        }
        case 6:
        {
            cout << "The circular linked list is: ";
            c1.printList();
            break;
        }
        case 7:
        {
            cout << "Exiting the list..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 7);

    return 0;
}
