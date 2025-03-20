#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

struct LIST {
    Node* pHead;
    Node* pTail;
    LIST() {
        pHead = nullptr;
        pTail = nullptr;
    }
};

void CreateEmptyList(LIST& L) {
    L.pHead = nullptr;
    L.pTail = nullptr;
}

void InsertAtHead(LIST& L, int value) {
    Node* newNode = new Node(value);
    if (L.pHead == nullptr) {
        L.pHead = L.pTail = newNode;
    } else {
        newNode->next = L.pHead;
        L.pHead = newNode;
    }
}

void InsertAtTail(LIST& L, int value) {
    Node* newNode = new Node(value);
    if (L.pHead == nullptr) {
        L.pHead = L.pTail = newNode;
    } else {
        L.pTail->next = newNode;
        L.pTail = newNode;
    }
}

void CreateList(LIST& L) {
    int type, value;
    while (true) {
        cin >> type;
        if (type == -1) break;
        cin >> value;
        if (type == 0) {
            InsertAtHead(L, value);
        } else if (type == 1) {
            InsertAtTail(L, value);
        }
    }
}

void PrintList(const LIST& L) {
    if (L.pHead == nullptr) {
        cout << "Empty List." << endl;
        return;
    }
    for (Node* current = L.pHead; current != nullptr; current = current->next) {
        cout << current->data;
        if (current->next != nullptr) cout << " ";
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
