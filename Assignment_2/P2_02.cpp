
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

void binarySearch(vector<int> &A)
{
    int x; cin >> x;

    sort(A.begin(), A.end());

    for (auto num : A)
        cout << num << " ";
    cout << endl;

    int n = A.size(), left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        cout << "Left="<< left << " " << "Right=" << right << " " << "Mid=" << mid << endl;
        if (A[mid] == x) return;
        else
        if (A[mid] > x) right = mid - 1;
        else
            left = mid + 1;
    }
}

int main() {
	vector<int> A;
	Input(A);
	binarySearch(A);
	return 0;
}
