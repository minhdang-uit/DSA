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
    if (p == NULL) exit(1);

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
        if (tmp == NULL) exit(1);
        AddTail(L, tmp);
    }
}   

void add_after_k_th(LIST &L, int y, int k) {
    if (k < 1) return; 

    node temp = L.pHead;
    int count = 1;

    while (temp != NULL && count < k) {
        temp = temp->pNext;
        count++;
    }

    if (temp != NULL) {
        node newNode = CreateNode(y);
        newNode->pNext = temp->pNext;
        temp->pNext = newNode;

        if (temp == L.pTail) 
            L.pTail = newNode; 
    }
}
void PrintList(LIST &L)
{
    if (L.pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }
    node p = L.pHead;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->pNext;
    }
}

int main() {
    LIST L;
	int k, Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> k >> Y;
	add_after_k_th(L, Y, k);

	PrintList(L);

    return 0;
}
