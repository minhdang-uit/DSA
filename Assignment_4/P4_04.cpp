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
   int pivot = arr[(left + right) / 2];
   int i = left, j = right;

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

int quickSort(vector<int> &a, int left, int right)
{
    if (left >= right) return 1; 
	int cnt = 1; 
    int x = a[(left+right)/2], i = left, j = right;
	while(i < j) 
    {
		while (a[i] < x) 
            i++; 
		while (a[j] > x) 
            j--;
		if (i <= j)
			swap(a[i++], a[j--]);
	}
	if (left < j) cnt += quickSort(a, left, j);
    if (right > i) cnt += quickSort(a, i, right);    
    return cnt;       
}

void Sort(vector <int> arr) {
    if (!arr.empty()) cout << quickSort(arr, 0, (int)arr.size() - 1); 
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
