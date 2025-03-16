/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
/*Sắp xếp danh sách A tăng dần bằng phương pháp HeapSort.

Hiển thị 2 giá trị hoán vị đầu - cuối của danh sách A trong mỗi lần hiệu chỉnh.

Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử. Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng 0 và không thêm số 0 vào danh sách A. 


INPUT
Nhập giá trị các phần tử của danh sách A.  
OUTPUT
N là số lượng phần tử trong danh sách A cần được sắp xếp ở mỗi lần hiệu chỉnh.
Xuất 2 giá trị đầu - cuối của danh sách A trong mỗi lần hiệu chỉnh theo mô tả.*/
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

void Heapify(vector<int> &a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
        {
            swap(a[i], a[largest]);
            Heapify(a, n, largest);
        }
}

void BuildHeap(vector<int> &a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i);
}

void HeapSort(vector<int> &a, int n)
{
    BuildHeap(a, n);
    for (int i = n-1; i > 0; i--)
    {
        cout << "N=" << n << ": swap " << a[i] << " - " << a[0] << endl;
        swap(a[0], a[i]);
        n--;
        Heapify(a,n,0);
    }
}

void Sort(vector<int> a)
{
    int n = a.size();
    HeapSort(a, n);
}
int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
