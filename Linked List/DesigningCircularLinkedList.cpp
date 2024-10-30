#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val = 0)
    {
        data = val;
        next = NULL;
    }
};

class Create
{
public:
    Node *head;

    Create()
    {
        head = NULL;
    }

    void addHead(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;

            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtLocation(int location, int x)
    {
        Node *newNode = new Node(x);

        if (location < 1)
        {
            cout << "Invalid location" << endl;
            return;
        }

        if (location == 1)
        {
            addHead(x);
            return;
        }
        else
        {
            Node *temp = head;
            for (int i = 1; i < location - 1; i++)
            {
                temp = temp->next;
                if (temp == head)
                {
                    cout << "Invalid location" << endl;
                    return;
                }
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void delHead()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *temp = head;

            // Find the last node
            while (temp->next != head)
            {
                temp = temp->next;
            }

            Node *toDelete = head;
            temp->next = head->next;
            head = head->next;

            delete toDelete;
        }
    }

    void delAtLocation(int location)
    {
        if (location < 1)
        {
            cout << "Invalid location" << endl;
            return;
        }

        if (location == 1)
        {
            delHead();
            return;
        }
        else
        {
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

            Node *toDelete = temp->next;
            temp->next = toDelete->next;

            delete toDelete;
        }
    }

    void printList()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }
};

int main()
{
    Create c;
    c.addHead(10);
    c.addHead(20);
    c.addHead(30);
    c.printList();

    c.insertAtLocation(2, 25);
    c.printList();

    c.insertAtLocation(1, 5);
    c.printList();

    c.delHead();
    c.printList();

    c.delAtLocation(3);
    c.printList();

    return 0;
}
