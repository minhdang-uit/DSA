
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

void insertionSort(vector<int> &A)
{
    for (int i = 1; i < A.size(); i++)
    {
        int key = A[i], j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        cout << "i="<< i << " " << "e=" << key << " ";
            for (int num : A) cout << num << " ";
            cout << endl;
    }
}

int main() {
	vector<int> A;
	Input(A);
	insertionSort(A);
	return 0;
}
