// Doubly Linked List
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int v)
    {
        data = v;
        next = NULL;
        prev = NULL;
    }
};

class Create
{
    Node *head;

public:
    Create()
    {
        head = NULL;
    }

    void addHead(int v)
    {
        Node *newNode = new Node(v);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addAtLocation(int location, int v)
    {
        if (location == 0)
        {
            addHead(v);
            return;
        }

        Node *newNode = new Node(v);
        Node *p = head;

        for (int i = 0; i < location - 1; i++)
        {
            if (p == NULL)
            {
                cout << "Location is out of bounds.\n";
                return;
            }
            p = p->next;
        }

        if (p == NULL)
        {
            cout << "Invalid position.\n";
            return;
        }

        newNode->next = p->next;
        newNode->prev = p;

        if (p->next != NULL)
        {
            p->next->prev = newNode;
        }
        p->next = newNode;
    }

    void delHead()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
    }

    void delAtLocation(int location)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (location == 0)
        {
            delHead();
            return;
        }

        Node *p = head;

        for (int i = 0; i < location; i++)
        {
            if (p == NULL)
            {
                cout << "Location is out of bounds\n";
                return;
            }
            p = p->next;
        }

        if (p == NULL)
        {
            cout << "Location is out of bounds\n";
            return;
        }

        if (p->prev != NULL)
        {
            p->prev->next = p->next;
        }
        if (p->next != NULL)
        {
            p->next->prev = p->prev;
        }

        delete p;
    }
    void RevList()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
        }
        Node *temp = NULL;
        Node *p = head;
        while (p != NULL)
        {
            temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = p->prev;
        }
        if (temp != NULL)
        {
            head = temp->prev;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Create c2;
    int choice;
    do
    {
        cout << "\nChoose the operations on circular doubly linked list:" << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at Location" << endl;
        cout << "3. delete head" << endl;
        cout << "4. Delete at location" << endl;
        cout << "5. Print the linked list" << endl;
        cout << "6. THE REVERSED LINKED LIST IS" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter the value: ";
            int value;
            cin >> value;
            c2.addHead(value);
            break;
        }
        case 2:
        {
            cout << "Enter the value: ";
            int value;
            cin >> value;
            cout << "At what Location:";
            int loc;
            c2.addAtLocation(loc, value);
            break;
        }
        case 3:
        {
            c2.delHead();
            break;
        }
        case 4:
        {
            cout << "Enter the position to be deleted: ";
            int position;
            cin >> position;
            c2.delAtLocation(position);
            break;
        }
        case 5:
        {
            cout << "The Doubly linked list is: ";
            c2.printList();
            break;
        }
        case 6:
        {
            cout << "Reversing the list..." << endl;
            c2.RevList();
            break;
        }
        case 7:
        {
            cout << "Exiting the list" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
    } while (choice != 8);

    return 0;
}
