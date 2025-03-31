/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
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
        p->info = {x,y};
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


bool isSymmetric(POINT p1, POINT p2) {
    return (p1.ox == p2.ox && p1.oy == -p2.oy && p1.oy != 0); 
}

void Fun(LIST L) {
    if (L.pHead == NULL) {
        cout << "Empty";
        return;
    }
    
    bool found = false;
    NODE* p1 = L.pHead;
    
    while (p1 != NULL) 
    {
        NODE* p2 = p1->pNext;
        while (p2 != NULL) 
        {
            if (isSymmetric(p1->info, p2->info)) 
            {
                cout << "(" << p1->info.ox << "," << p1->info.oy << ")   ";
                cout << "(" << p2->info.ox << "," << p2->info.oy << ")" << endl;
                found = true;
            }
            p2 = p2->pNext;
        }
        p1 = p1->pNext;
    }
    
    if (!found) {
        cout << "NotFound";
    }
}

int main() {
    LIST L; 
    CreateList(L);  //Input
    Fun(L);	           //Output
    return 0;
}