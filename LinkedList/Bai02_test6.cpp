#include <iostream>
#include <math.h>
using namespace std; 

struct POINT{
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
        NODE *p = new NODE;
        p->info = {x, y};
        p->pNext = NULL;
        if (L.pHead == NULL)
            L.pHead = L.pTail = p;
        else
        {
            L.pTail->pNext = p;
            L.pTail = p;
        }
    }
}

double Distance(POINT p)
{
    return sqrt(p.ox * p.ox + p.oy * p.oy);
}

void Fun(LIST L)
{
   if (L.pHead == NULL) {
        cout << "Empty" << endl;
        return;
    }

   
    bool foundOy = false;
    for (NODE *p = L.pHead; p != NULL; p = p->pNext) {
        if (p->info.ox == 0) {
            if (foundOy) cout << " ";
            cout << "(" << p->info.ox << "," << p->info.oy << ")";
            foundOy = true;
        }
    }
    if (!foundOy) cout << "NotFound";
    cout << endl;

    
    bool foundOx = false;
    for (NODE *p = L.pHead; p != NULL; p = p->pNext) {
        if (p->info.oy == 0) {
            if (foundOx) cout << " ";
            cout << "(" << p->info.ox << "," << p->info.oy << ")";
            foundOx = true;
        }
    }
    if (!foundOx) cout << "NotFound";
    cout << endl;
}
int main() {
    LIST L; 
    CreateList(L);  //Input
    Fun(L);	           //Output
    return 0;
}
