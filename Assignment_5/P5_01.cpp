/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
using namespace std;

struct NODE
{
    int data;
    NODE *Next;
};

struct LIST
{
    NODE *Head;
    NODE *Tail;
};

typedef struct NODE *node;
void CreateEmptyList(LIST &L)
{
    L.Head = NULL;
    L.Tail = NULL;
}

node CreateNode(int x)
{
    node p = new NODE();
    if (p == NULL) exit(1);
    p->data = x;
    p->Next = NULL;
    return p;
}

void AddHead(LIST &L, NODE *p)
{
    if (L.Head == NULL)
    {
        L.Head = p;
        L.Tail = L.Head;
    }
    else
    {
        p->Next = L.Head;
        L.Head = p;
    }  
}

void CreateList(LIST &L)
{
    int x;
    while  (true)
    {
        cin >> x;
        if (x == -1) break;
        node tmp = CreateNode(x);
        AddHead(L, tmp);
    }
}

void PrintList(LIST L)
{
    if (L.Head == NULL)
    {
        cout << "Empty List." << endl;
        return;
    }
    node p = L.Head;
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
    PrintList(L);

    return 0;
}