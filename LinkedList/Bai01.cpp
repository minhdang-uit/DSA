/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <iostream>
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
    Node* head;
    LIST() {
        head = nullptr;
    }
};

void CreateEmptyList(LIST& L) {
    L.head = nullptr;
}

void InsertAtHead(LIST& L, int value) {
    Node* newNode = new Node(value);
    newNode->next = L.head;
    L.head = newNode;
}

void CreateList(LIST& L) {
    int value;
    while (true) {
        cin >> value;
        if (value == -1) break;
        InsertAtHead(L, value);
    }
}

void PrintList(const LIST& L) {
    if (L.head == nullptr) {
        cout << "Empty List." << endl;
        return;
    }
    Node* current = L.head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) cout << " ";
        current = current->next;
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
