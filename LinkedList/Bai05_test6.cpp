#include <iostream>
using namespace std;

struct POINT {
    int ox, oy;
};

struct NODE {
    POINT info;
    NODE* pNext;
};

struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateList(LIST &L) 
{
    L.pHead = L.pTail = NULL;
    int x, y;
    while (true) 
    {
        cin >> x;
        if (x == -1) break;
        cin >> y;

        NODE* p = new NODE;
        p->info = {x, y};
        p->pNext = NULL;

        if (L.pHead == NULL) 
        
            L.pHead = L.pTail = p;
         else {
            L.pTail->pNext = p;
            L.pTail = p;
         }
    }
}

void Fun(LIST &L) 
{
    NODE *p = L.pHead;
    NODE *prev = NULL;

    while (p != NULL) 
    {
        if (p->info.ox == p->info.oy)
        {
            NODE *temp = p;
            if (prev == NULL) 
                L.pHead = p->pNext;
            else 
                prev->pNext = p->pNext;
            if (p == L.pTail) 
                L.pTail = prev; 
            p = p->pNext;
            delete temp;
        } 
        else 
        {
            prev = p;
            p = p->pNext;
        }
    }
}

void PrintList(LIST L) {
    if (L.pHead == NULL) 
    {
        cout << "Empty" << endl;
        return;
    }

    NODE* p = L.pHead;
    while (p != NULL) 
    {
        cout << "(" << p->info.ox << "," << p->info.oy << ")" << endl;
        p = p->pNext;
    }
}

int main() {
    LIST L;
    CreateList(L); //Input
    Fun(L);        //Remove
    PrintList(L);  //Output
    return 0;
}
