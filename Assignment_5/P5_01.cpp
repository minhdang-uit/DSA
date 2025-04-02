/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword


Tạo danh sách liên kết đơn lưu trữ các số nguyên ( giá trị số nguyên < 1000 ). Các số được lần lượt thêm vào đầu danh sách, kết thúc khi gặp giá trị -1.

INPUT
Dãy các số nguyên, số cuối cùng là -1. Mặc định rằng các số nhập đúng điều kiện.

OUTPUT
Danh sách được in trên một dòng với mỗi số cách nhau bởi một khoảng trắng.
*/
#include <iostream>

using namespace std;

struct NODE
{
    int data;
    NODE *pNext;
};

typedef struct NODE *node;

struct LIST
{
    node pHead;
    node pTail;
};

void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

node CreateNode(int x)
{
    node p = new NODE;
    if (p = NULL) exit(1);

    p->data = x;
    p->pNext = NULL;
    return p;
}

void AddHead(LIST &L, node p)
{
    if (L.pHead == NULL)
    {
        L.pHead = p;
        L.pTail = L.pHead;
    }
    else
    {
        p->pNext = L.pHead;
        L.pHead = p;
    } 
}

void CreateList(LIST &L)
{
    int x;
    while(true)
    {
        cin >> x;
        if (x == -1) break;
        node temp = CreateNode(x);
        AddHead(L, temp);
    }
}

void PrintList(LIST L)
{
    if (L.pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }
    node p = L.pHead;
    while (p)
    {
        cout << p->data << ' ';
        p = p->pNext;
    }
}

int main() {
    LIST L;
	CreateEmptyList(L);
	CreateList(L);
    PrintList(L);

    return 0;
}