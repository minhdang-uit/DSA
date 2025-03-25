/*Sắp xếp mảng một chiều các số nguyên tăng dần bằng phương pháp Selection sort. Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử. Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng 0 và không thêm số 0 vào danh sách A. 

INPUT 
Nhập giá trị các phần tử của danh sách A. 
OUTPUT 
Xuất ra các bước i thể hiện quá trình sắp xếp tăng dần bằng SelectionSort*/

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
    while (cin >> x && x != 0)
        A.push_back(x);
}

void printArray(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
        cout << A[i] << " ";
    cout << endl;
}
void selectionSort(vector<int> &A)
{
    for (int i = 0; i < A.size() - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < A.size(); j++)
            if (A[min_idx] > A[j])
                min_idx = j;
        swap(A[i], A[min_idx]);
        cout << "i=" << i << ": ";
        for (int num : A)
            cout << num << " ";
        cout << endl;
    }
}

int main() {
	vector<int> A;
	Input(A);
	selectionSort(A);
	return 0;
}
