#include <bits/stdc++.h>
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

void AddHead(LIST &L, node p)
{
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    } 
}

void CreateList(LIST &L)
{
    int x;
    bool empty = true;

    while (cin >> x)
    {
        if (x == -1) break;
            empty = false;
        node tmp = CreateNode(x);
        if (tmp == NULL) exit(1);
        AddHead(L, tmp);
    }

    if (empty == true) 
    {
        cout << "Empty List.";
        exit(0);
    }
}

bool isArmstrong(int n)
{
    int original = n, sum = 0, num_digits = 0;

    int temp = n;
    while (temp > 0)
    {
        num_digits++;
        temp /= 10;
    }
    
    temp = n;
    while (temp > 0)
    {
        int powered = 1;
        int digit = temp % 10;
        for (int i = 0; i < num_digits; i++)
                powered *= digit;

        sum += powered;
        temp /= 10;
    }
    return sum == original;
}

void PrintList_Armstrong(LIST &L)
{
    node p = L.pHead;

    bool found = false;

    while (p != NULL)
    {
        if (isArmstrong(p->data))
            {
                cout << p->data << " ";
                found = true;
            }
            p = p->pNext;
    }

    if (!found) cout << "Không có số armstrong trong mảng.";
    cout << endl;
}

int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList_Armstrong(L);

    return 0;
}
