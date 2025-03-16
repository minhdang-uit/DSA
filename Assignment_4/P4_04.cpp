/*Sắp xếp danh sách A tăng dần bằng phương pháp QuickSort.

Đếm số đoạn được phân hoạch trong quá trình sắp xếp.

Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử. Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng 0 và không thêm số 0 vào danh sách A. 

INPUT
Nhập giá trị các phần tử của danh sách A.  
OUTPUT
Xuất ra số đoạn được phân hoạch trong quá trình sắp xếp. */

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

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = 0; j < right - 1; j++)
        if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void quickSort(vector<int> &arr, int left, int right, int &count)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi - 1, count);
        quickSort(arr, pi + 1, right, count);
        count++;
    }
}

void Sort(vector<int> &arr)
{
    int count = 0;
    if (!arr.empty())
        quickSort(arr,0, arr.size() - 1, count);
    
    cout << count;
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
