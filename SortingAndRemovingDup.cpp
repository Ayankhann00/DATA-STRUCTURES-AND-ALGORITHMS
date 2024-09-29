 
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
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
    void sortList()
    {
        if (head == NULL || head->next == NULL)
            return;

        Node *p = head;

        while (p != NULL)
        {
            Node *q = head;

            while (q->next != NULL)
            {
                if (q->data > q->next->data)
                {

                    int temp = q->data;
                    q->data = q->next->data;
                    q->next->data = temp;
                }

                q = q->next;
            }

            p = p->next;
        }
    }
    void removeDup()
    {
        if (head == NULL || head->next == NULL)
            return;
        Node *p = head;
        Node *q = head->next;
        while (q != NULL)
        {
            if (p->data != q->data)
            {
                p = q;
                q = q->next;
            }
            else
            {
                p->next = q->next;
                delete q;
                q = p->next;
            }
        }
    }
};
int main()
{
    Create LinkedList;

    LinkedList.addHead(10);
    LinkedList.addHead(20);
    LinkedList.addHead(50);
    LinkedList.addHead(40);
    LinkedList.addHead(30);
    LinkedList.addHead(40);
    LinkedList.addHead(80);
    LinkedList.printList();
    LinkedList.sortList();
    cout << "THE SORTED LINKED LIST IS:" << endl;
    LinkedList.printList();
    LinkedList.removeDup();
    cout << "THE LINKED LIST AFTER REMOVING DUPLICATES IS:" << endl;
    LinkedList.printList();

    return 0;
}
