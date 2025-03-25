#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &A)
{
    int x;
    while (cin >> x && x != 0)
        A.push_back(x);
}

void binarySearch(vector<int> &A)
{
    sort(A.begin(), A.end());
  
    int x; cin >> x;

    for (int num : A)
        cout << num << " ";
    cout << endl;

    int n = A.size(), left = 0, right = n -1, count = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        count++;
        if (A[mid] == x)
        {
            cout << count << endl;
            return;
        }
        else 
        if (A[mid] < x)   
            left = mid + 1;
        else 
            right = mid - 1;
    }
    cout << count << endl;
}

int main() {
	vector<int> A;
	Input(A);
	binarySearch(A);
	return 0;
}
