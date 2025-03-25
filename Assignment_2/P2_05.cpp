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

    sort(A.begin(), A.end(), greater<int>());

    for (int num : A)
        cout << num << " ";
    cout << endl;

    int left = 0, right = A.size() - 1, count = 0;

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
