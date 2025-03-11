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
    while (cin >> num)
    {
        if (!num) break;
        A.push_back(num);
    }
}
void linearSearch(vector<int> &A)
{
    vector<int> result;
    
    int x; cin >> x;

    for (int i = 0; i < A.size(); i++)
        if (A[i] == x && i % 2)
            result.push_back(i);

    if (!result.empty()) {
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
    else cout << "No Find";
}
int main() {
	vector<int> A;
	Input(A);
	linearSearch(A);
	return 0;
}
