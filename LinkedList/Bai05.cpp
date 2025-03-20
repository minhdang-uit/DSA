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
    int value;
    while (true) {
        cin >> value;
        if (value == -1) break;
        InsertAtTail(L, value);
    }
}

string searchX(Node* head, int X) {
    for (Node* current = head; current != nullptr; current = current->next) {
        if (current->data == X) return "true";
    }
    return "false"; 
}

int main() {
    LIST L;
    int X;
    CreateEmptyList(L);

    CreateList(L);
    std::cin >> X;
    cout << searchX(L.pHead, X);

    return 0;
}
