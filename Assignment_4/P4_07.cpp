/*Sắp xếp danh sách A tăng dần bằng phương pháp HeapSort.

Hiển thị sự thay đổi của danh sách A trong mỗi lần hiệu chỉnh.

Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử. Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng 0 và không thêm số 0 vào danh sách A.


INPUT
Nhập giá trị các phần tử của danh sách A.
OUTPUT
N là số lượng phần tử trong danh sach A cần được sắp xếp ở mỗi lần hiệu chỉnh.
Xuất kết quả của danh sách A trong mỗi lần hiệu chỉnh.*/

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
    while (tmp > 0)
    {
        v.push_back(tmp);
        cin >> tmp;
    }
}

void heapify(vector<int> &a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void buildHeap(vector<int> &a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

void heapSort(vector<int> &a, int n)
{
    buildHeap(a, n);
    for (int i = n - 1; i > 0; i--)
    {
        cout << "N=" << n << endl;
        swap(a[i], a[0]);
        n--;
        for (int j = 0; j < a.size(); j++)
            cout << a[j] << " ";
            heapify(a, n, 0);
        cout << endl;
    }
}
void Sort(vector<int> &a)
{
    heapSort(a, a.size());
}
int main()
{
    vector<int> A;
    Input(A);
    Sort(A);
    return 0;
}
