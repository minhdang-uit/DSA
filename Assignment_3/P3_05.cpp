/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &A)
{
    int x;
    while(cin >> x && x != 0)
        A.push_back(x);
}

void printArray(const vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
void insertionSort(vector<int> &A)
{
    for (int i = 1; i < A.size(); i++)
    {
        int e = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] < e)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = e;

        cout << "i=" << i << ": e=" << e << ": ";
        printArray(A);
    }
}

int main() {
	vector<int> A;
	Input(A);
	insertionSort(A);
	return 0;
}
