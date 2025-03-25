#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &A)
{
    int num;
    while (cin >> num && num != 0)
        A.push_back(num);
}

void linearSearch(vector<int> &A)
{
    int n = A.size(), left = 0, right = n - 1;

    int x; cin >> x;

    vector<int> pos;

    for (int i = 0; i < n; i++)
        if (A[i] == x)
            pos.push_back(i);

    if (!pos.empty())
        for (int i = 0; i < pos.size(); i++)
            cout << pos[i] << " ";
    else cout << "No Find";    
}

int main() {
	vector<int> A;
	Input(A);
	linearSearch(A);
	return 0;
}
