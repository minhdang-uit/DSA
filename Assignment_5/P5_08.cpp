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

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

void PrintList_Prime(LIST &L)
{
    node tmp = L.pHead;
    bool found = false;
    while (tmp != NULL)
    {
        if (isPrime(tmp->data))
        {
            cout << tmp->data << " ";
            found = true;
        }
            tmp = tmp->pNext;
    }
    if (found == false) cout << "Không có số nguyên tố trong mảng.";
    cout << endl;
}

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList_Prime(L);

    return 0;
}