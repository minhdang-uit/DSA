#include <iostream>
#include <cmath>
#include <algorithm>
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

NODE *CreateNode(int x)
{
    node p = new NODE;
    if (p == NULL) exit(1);

    p->data = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &list, node p)
{
    if (list.pHead == NULL)
    {
        list.pHead = p;
        list.pTail = list.pHead;
    }
    else
    {
        list.pTail->pNext = p;
        list.pTail = p;
    }
}

void CreateList(LIST &list)
{
    int x;
    while (cin >> x) 
    {
        if (x == -1) break;
        node tmp = CreateNode(x);
        AddTail(list, tmp);
    }
}

bool is_prime(int n)
{
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void add_after_all_prime(LIST &L, int Y)
{
    node p = L.pHead;
    while (p != NULL)
    {
        if (is_prime(p->data))
        {
            node tmp = CreateNode(Y);
            tmp->pNext = p->pNext;
            p->pNext = tmp;
            if (p == L.pTail)
                L.pTail = tmp;
            p = tmp->pNext;
        }
        else
        {
            p = p->pNext;
        }
    }
}

void PrintList(LIST L)
{
    node p = L.pHead;

    while (p != NULL)
    {
        cout << p->data;
        if (p->pNext != NULL) cout << " ";
        p = p->pNext;
    }
    cout << endl;
}
int main() {
    LIST L;
	int Y;

	CreateEmptyList(L);

	CreateList(L);

	std::cin >> Y;
	add_after_all_prime(L, Y);

	PrintList(L);

    return 0;
}
