/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &A)
{
    int num;
    while(cin >> num && num != 0)
        A.push_back(num);
}

void linearSearch(vector<int> &A)
{
    int x; cin >> x;

    bool found = false;
    for (int i = A.size() - 1; i >= 0; i--)
        if (A[i] == x)
           {
            cout << i;
            found = true;
            break;
           }
    if (!found) cout << "No Find";
        
}

int main() {
	vector<int> A;
	Input(A);
	linearSearch(A);
	return 0;
}
