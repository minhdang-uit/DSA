/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}

void Output(vector<int> &a, int left, int right, int pivot) {
    cout << "Phan hoach doan left=" << left << " - right=" << right 
         << " - pivot=" << pivot << ":\n";
    for (int x : a) {
        cout << x << "\t";
    }
    cout << "\n";
}
void quickSort(vector<int> &a, int left, int right, int x)
{
    
    if (left >= right)
    {
        Output(a, left, right, x);
        return;
    }
    
    int pivot = a[(left+right)/2], i = left, j = right;
	while(i < j) 
    {
		while (a[i] < pivot) 
            i++; 
		while (a[j] > pivot) 
            j--;
		if (i <= j)
			swap(a[i++], a[j--]);
	}
    Output(a, left, right, pivot);
    if (left < j) quickSort(a, left, j, pivot);
    if (right > i) quickSort(a, i, right, pivot);           
}

void Sort(vector<int> &a)
{
    if (!a.empty())
        quickSort(a, 0, (int)a.size() - 1, 0);
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
