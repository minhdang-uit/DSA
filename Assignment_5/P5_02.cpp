#include <iostream>

using namespace std;

struct NODE {
    int num; 
    NODE* pNext; 
}; 

struct LIST {
    NODE* pHead; 
    NODE* pTail; 
};

void CreateEmptyList(LIST &list) {
    list.pHead = NULL;
    list.pTail = NULL; 
}

NODE* CreateNode(int x) {
    NODE* p = new NODE; 
    if (p == NULL) exit(1); 
    p->num = x; 
    p->pNext = NULL; 
    return p; 
}

void AddHead(LIST &list, NODE* p) {
    if (list.pHead == NULL) {
        list.pHead = p; 
        list.pTail = list.pHead; 
    }
    else {
        p->pNext = list.pHead; 
        list.pHead = p; 
    }
}

void AddTail(LIST &list, NODE* p) {
    if (list.pHead == NULL) {
        list.pHead = p; 
        list.pTail = list.pHead; 
    }
    else {
        list.pTail->pNext = p; 
        list.pTail = p; 
    }
}

void CreateList(LIST &list) {
    int x; 
    while (cin >> x) {
        if (x == -1) return; 
        AddTail(list, CreateNode(x)); 
    }
}

void PrintList(NODE* p) {
    if (p == NULL) {
        cout << "Empty List."; 
        return; 
    }
    NODE* q; 
    q = p; 
    while (q) {
        cout << q->num << ' '; 
        q = q->pNext; 
    }
}

void RemoveList(LIST &list) {
    NODE* p; 
    while (list.pHead != NULL) {
        p = list.pHead; 
        list.pHead = p->pNext; 
        delete p; 
    }
    list.pTail = NULL;
}
int main() {
    LIST L;
	CreateEmptyList(L);

	CreateList(L);
    PrintList(L.pHead);

    return 0;
}
