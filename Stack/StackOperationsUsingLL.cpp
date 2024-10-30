#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *top;
    Node *next;
    Node()
    {
        top = NULL;
        next = NULL;
    }
};
class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    void push(int x)
    {
        Node *t = new Node();
        if (t == NULL)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            t->data = x;
            t->next = top;
            top = t;
        }
    }
    void pop()
    {
        Node *p = top;
        if (top == NULL)
        {
            cout << "Empty Stack" << endl;
        }
        else
        {
            top = top->next;
            int x = p->data;
            delete p;
            cout << "Popped element is " << x << endl;
        }
    }
    int peek(int pos)
    {
        Node *s = top;
        for (int i = 0; s != NULL && i < pos - 1; i++)
        {
            s = s->next;
        }
        if (s != NULL)
        {
            cout << "The element is:" << s->data << endl;
        }
        else
        {
            return -1;
        }
    }
    int StackTop()
    {
        if (top != NULL)
        {
            return top->data;
        }
        else
        {
            return -1;
        }
    }
};
int main()
{
    Stack stk;
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);
    stk.push(7);
    cout << "The top element is: " << stk.StackTop() << endl;
    stk.pop();
    cout << "Element at position 3 is: " << stk.peek(3) << endl;
    cout << "The top element is: " << stk.StackTop() << endl;
    return 0;
}
