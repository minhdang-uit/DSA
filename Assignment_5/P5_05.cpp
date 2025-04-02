#include <iostream>

using namespace std;

struct NODE
{
    int data;
    NODE *pNext;
};

typedef struct NODE *node;

struct LIST
{
    node pHead;
    node pTail;
};

void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

node CreateNode(int x)
{
    node p = new NODE;
    if (p == NULL) return NULL;

    p->data = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &L, node p)
{
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        L.pTail->pNext = p;
        L.pTail = p;
    }
    
}

void CreateList(LIST &L) 
{
    int x;
    while (cin >> x)
    {
        if (x == -1) break;
        node tmp = CreateNode(x);
        AddTail(L, tmp);
    }
}   

void add_afterX_1(LIST &L, int y, int x)
{
    node temp = L.pHead;
    while (temp != NULL && temp->data != x)
        temp = temp->pNext;

    if (temp != NULL)
    {
        node newNode = CreateNode(y);
        newNode->pNext = temp->pNext;
        temp->pNext = newNode;
    }
}

void PrintList(node head)
{
    node tmp = head;
    if (tmp == NULL)
    {
        cout << "Empty List." << endl;
        return;
    }
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->pNext;
    }
}
int main() {
    LIST L;
	int X, Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> X >> Y;
	add_afterX_1(L, Y, X);

	PrintList(L.pHead);

    return 0;
}


