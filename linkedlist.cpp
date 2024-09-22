// reversing a linked list using recursion
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
} *first = NULL;
void create(int a[], int n)
{
    Node *t, *p;
    first = new Node;
    first->data = a[0];
    first->next = NULL;
    p = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = NULL;
        p->next = t;
        p = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
void Rdisplay(struct Node *p)
{
    if (p != NULL)
    {
        Rdisplay(p->next);
        cout << p->data << " ";
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6};
    create(A, 6);
    cout << "Original Linked List: ";
    Display(first);
    cout << endl;
    cout << "Reversed Linked List: ";
    Rdisplay(first);

    return 0;
}
