#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

struct LIST
{
    Node* pHead;
    Node* pTail;
    LIST()
    {
        pHead = nullptr;
        pTail = nullptr;
    }
};

void CreateEmptyList(LIST& L)
{
    L.pHead = nullptr;
    L.pTail = nullptr;
}

void InsertAtTail(LIST& L, int value)
{
    Node* newNode = new Node(value);
    if (L.pHead == nullptr)
        L.pHead = L.pTail = newNode;
    else
    {
        L.pTail->next = newNode;
        L.pTail = newNode;
    }
}

void CreateList(LIST& L)
{
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1) break;
        InsertAtTail(L, value);
    }
}

void PrintList(Node* head)
{
    if (head == nullptr)
    {
        cout << "Empty List." << endl;
        return;
    }
    for (Node* current = head; current != nullptr; current = current->next) {
        cout << current->data;
        if (current->next != nullptr) cout << " ";
    }
    cout << endl;
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    PrintList(L.pHead); 

    return 0;
}
