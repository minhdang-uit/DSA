
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

void Insert(TREE &tree, int x)
{
    if (tree == NULL)
    {
        tree = CreateNode(x);
        return;
    }

    if (x == tree->key) return;
    if (x < tree->key) Insert(tree->pLeft, x);
    else Insert(tree->pRight, x);
}

void CreateTree(TREE &tree)
{
    int x;
    while (true)
    {
        cin >> x;
        if (x == -1) break;
        Insert(tree, x);
    }
}

TREE Findmin(TREE tree)
{
    while (tree && tree->pLeft != NULL)
        tree = tree->pLeft;
    return tree;
}

void DeleteNode(TREE &tree, int x)
{
    if (tree == NULL) return;
    
    if (x < tree->key)
        DeleteNode(tree->pLeft, x);
    else if (x > tree->key)
        DeleteNode(tree->pRight, x);
    else
    {
        if (tree->pLeft == NULL)
        {
            TREE tmp = tree->pRight;
            delete tree;
            tree = tmp;
        }
        else if (tree->pRight == NULL)
        {
            TREE tmp = tree->pLeft;
            delete tree;
            tree = tmp;
        }
        else
        {
            TREE tmp = Findmin(tree->pRight);
            tree->key = tmp->key;
            DeleteNode(tree->pRight, tmp->key);
        }        
    }
}

void NLR(TREE tree) {
    if (tree == NULL) return;
    cout << tree->key << ' '; 
    NLR(tree->pLeft); 
    NLR(tree->pRight); 
}

void PrintTree(TREE tree) {
    if (tree == NULL) {
        cout << "Empty Tree."; 
        return; 
    }
    NLR(tree); 
}


int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	DeleteNode(T, x);

	PrintTree(T);
	return 0;
}
