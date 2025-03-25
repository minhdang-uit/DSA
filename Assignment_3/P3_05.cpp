/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
/*Sắp xếp mảng một chiều các số nguyên giảm dần bằng phương pháp insertion sort. Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử. Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng 0 và không thêm số 0 vào danh sách A. 

INPUT 
Nhập giá trị các phần tử của danh sách A. 
OUTPUT 
Xuất ra các bước i thể hiện quá trình sắp xếp tăng dần bằng InsertionSort*/
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
        while (j >= 0 && A[j] < key)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        cout << "i=" << i << ": " << "e=" << key << ": ";
        for (int num : A)
            cout << num << " ";
        cout << endl;
    }
}

int main() {
	vector<int> A;
	Input(A);
	insertionSort(A);
	return 0;
}
