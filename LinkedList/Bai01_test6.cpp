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
    
    NODE* p = L.pHead;
    int minDist2 = Distance(p->info);
    int maxDist2 = minDist2;

    for (; p != NULL; p = p->pNext) {
        int d = Distance(p->info);
        if (d > maxDist2) maxDist2 = d;
        if (d < minDist2) minDist2 = d;
    }


    bool firstMax = true;
    for (p = L.pHead; p != NULL; p = p->pNext) {
        int d = Distance(p->info);
        if (d == maxDist2) {
            if (!firstMax) cout << " ";
            cout << "(" << p->info.ox << "," << p->info.oy << ")";
            firstMax = false;
        }
    }
    cout << endl;


    bool firstMin = true;
    for (p = L.pHead; p != NULL; p = p->pNext) {
        int d = Distance(p->info);
        if (d == minDist2) {
            if (!firstMin) cout << " ";
            cout << "(" << p->info.ox << "," << p->info.oy << ")";
            firstMin = false;
        }
    }
    cout << endl;
}


int main() {
    LIST L; 
    CreateList(L);  //Input
    Fun(L);	           //Output
    return 0;
}
