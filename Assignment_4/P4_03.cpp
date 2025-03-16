/*Sắp xếp danh sách A giảm dần bằng phương pháp QuickSort. Trong quá trình sắp xếp, chọn phần tử pivot là phần tử ở giữa danh sách.

Danh sách A được nhập giá trị các phần tử và không giới hạn số lượng phần tử. Dừng thêm phần tử vào A nếu giá trị phần tử được nhập bằng 0 và không thêm số 0 vào danh sách A.

INPUT
Nhập giá trị các phần tử của danh sách A.
OUTPUT
Xuất ra kết quả của danh sách A sau khi được sắp xép giảm dần.*/
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

int partition(vector<int> &arr, int left, int right)
{
   int pivot = arr[(left + right) / 2];
   int i = left, j = right;

    while (i <= j)
    {
        while (arr[i] > pivot)
            i++;
        while (arr[j] < pivot)
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

void QuickSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int pi = partition(arr, left, right);
        if (left < pi - 1)
            QuickSort(arr, left, pi - 1);
        if (pi < right)
            QuickSort(arr, pi, right);
    }
    if (left == 0 && right == arr.size() - 1)
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
    cout << endl;   
}
int main()
{
    vector<int> A;
    Input(A);
    QuickSort(A, 0, A.size() - 1);
    return 0;
}
