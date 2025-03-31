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

void CreateList(LIST &L) {
    L.pHead = L.pTail = NULL;
    int x, y;
    while (true) {
        cin >> x;
        if (x == -1) break;
        cin >> y;

        NODE* p = new NODE;
        p->info = {x, y};
        p->pNext = NULL;

        if (L.pHead == NULL) {
            L.pHead = L.pTail = p;
        } else {
            L.pTail->pNext = p;
            L.pTail = p;
        }
    }
}

void Fun(LIST L) {
    if (L.pHead == NULL) {
        cout << "Empty" << endl;
        return;
    }

    bool found = false;
    for (NODE* p1 = L.pHead; p1 != NULL; p1 = p1->pNext) {
        if (p1->info.ox == 0 && p1->info.oy == 0) continue;
        for (NODE* p2 = p1->pNext; p2 != NULL; p2 = p2->pNext) {

            if (p2->info.ox == 0 && p2->info.oy == 0) continue;
            if (p1->info.ox == -p2->info.ox && p1->info.oy == -p2->info.oy) {
                cout << "(" << p1->info.ox << "," << p1->info.oy << ") ";
                cout << "(" << p2->info.ox << "," << p2->info.oy << ")" << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "NotFound" << endl;
    }
}

int main() {
    LIST L;
    CreateList(L);
    Fun(L);
    return 0;
}
