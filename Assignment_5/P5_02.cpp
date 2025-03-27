#include <iostream>
using namespace std;

struct NODE
{
    int data;
    NODE *Next;
};

struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

typedef struct NODE *node;

void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

node CreateNode(int x)
{
    node p = new NODE();
    if (p == NULL) exit(1);
    p->data = x;
    p->Next = NULL;
    return p;
}

void AddTail(LIST &L, NODE *p)
{
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        L.pTail->Next = p;
        L.pTail = p;
    }
}

void CreateList(LIST &L)
{
    int x;
    while(true)
    {
        cin >> x;
        if (x == -1) break;
        node temp = CreateNode(x);
        AddTail(L, temp);
    }
}

void PrintList(node head)
{
    if (head == NULL)
    {
        cout << "Empty List." << endl;
        return;
    }

    node p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->Next;
    }
    cout << endl;
}

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList(L.pHead);

    return 0;
}
