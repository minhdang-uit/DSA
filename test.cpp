
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

TREE CreateNode(int x)
{
    TREE p = new TNODE;
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

void InsertNode(TREE &T, int x)
{
    if (T == NULL)
    {
        T = CreateNode(x);
        return;
    }

    if (x == T->key) return;
    else if (x < T->key) InsertNode(T->pLeft, x);
    else InsertNode(T->pRight, x);    
}

void CreateTree(TREE &T)
{
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1) break;
        InsertNode(T, x);
    }
}

int CountNodes(TREE T)
{
    if (T == NULL) return 0;
    return 1 + CountNodes(T->pLeft) + CountNodes(T->pRight);
}

void TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(TREE T)
{
    if (T == NULL) return;

    TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T->pLeft);  // L
    TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T->pRight); // R
    
    int countLeft = CountNodes(T->pLeft);
    int countRight = CountNodes(T->pRight);
    if (countLeft == countRight + 1)
        cout << T->key << " ";  // N

    
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)

	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else TongSoNodeTrai_LonHon_TongSoNodePhai_1dv(T);

	return 0;
}
