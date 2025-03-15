/*Sắp xếp mảng một chiều các số nguyên tăng dần bằng phương pháp selection sort. Biết rằng số lượng phần tử của mảng < 100,000; giá trị các phần tử < 1 tỷ.

INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

Số nguyên đầu tiên: số lượng phần tử của mảng
Các số nguyên còn lại: giá trị của các phần tử của mảng
 

OUTPUT
"true" nếu mảng sắp xếp thành công. "false" nếu mảng sắp không thành công.*/

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

void NhapMang(int a[], int n)
{

}

void selection_sort_ascending(int a[], int n)
{
	
}

bool is_ascending(int a[], int n)
{
	return true;
}

int main() {
    int a[MAXN], n;

    std::cin >> n;

    NhapMang(a, n);

    selection_sort_ascending(a, n);

    std::cout << std::boolalpha << is_ascending(a, n);

    return 0;
}
