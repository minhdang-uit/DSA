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
    bool Empty = true;
    int x;
    while (cin >> x)
    {
        if (x == -1) break;
            Empty = false;
        node tmp = CreateNode(x);
        if (tmp == NULL) exit(1);
        AddTail(L, tmp);
    }
    if (Empty == true) 
    {
        cout << "Empty List.";
        exit(0);
    }
}

void PrintList_Odd(node head)
{
    
    bool found = false;

    node temp = head;

    while (temp != NULL )
    {
        if (abs(temp->data) % 2 == 1)
        {
            cout << temp->data << " ";
            found = true;
        }
        temp = temp->pNext;
    }

    if (!found) cout << "Không có số lẻ trong mảng.";
}

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList_Odd(L.pHead);

    return 0;
}
