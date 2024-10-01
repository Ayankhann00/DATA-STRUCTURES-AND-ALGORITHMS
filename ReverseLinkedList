#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node()
    {
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

        Node *newNode = new Node();
        newNode->data = data;

        if (head == NULL)
        {

            head = newNode;
        }
        else
        {

            newNode->next = head;
            head = newNode;
        }
    }
    void ReverseList()
    {
        Node *r = NULL; // prev node
        Node *p = head; // current node
        Node *q = NULL; // next node

        while (p != NULL)
        {
            q = p->next;
            p->next = r;
            r = p;
            p = q;
        }

        head = r;
    }
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL";
    }
};
int main()
{
    Create c;
    c.addHead(10);
    c.addHead(80);
    c.addHead(20);
    c.addHead(50);
    c.printList();
    cout << endl;
    cout << "The reversed linked list is:" << endl;
    c.ReverseList();
    c.printList();

    return 0;
}
