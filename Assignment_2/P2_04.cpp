
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
    int x; cin >> x;

    int count = 0;
    for (int i = 0; i < A.size(); i++)
        if (A[i] == x) count++;
    
    cout << count;
}

int main() {
	vector<int> A;
	Input(A);
	linearSearch(A);
	return 0;
}
