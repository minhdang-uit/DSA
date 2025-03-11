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

void binarySearch(vector<int> &A)
{
    sort(A.begin(), A.end(), greater<int>());

    int x;
    cin >> x;

    for (int num : A)
        cout << num << " ";
    cout << endl;

    int left = 0, right = A.size() - 1, count = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        cout << "Left=" << left << " " << "Right=" << right << " " << "Mid=" << mid << endl;

        if (A[mid] == x) return ;
        else if (A[mid] < x ) left = mid + 1;
            else right = mid - 1;
    }
}

int main() {
	vector<int> A;
	Input(A);
	binarySearch(A);
	return 0;
}
