/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword


Tìm giá trị X trong mảng 1 chiều lưu n phần tử ( <=400,000) các số nguyên (< 2 tỷ). Nếu tìm thấy, xuất "true". Ngược lại xuất "false". Yêu cầu: Viết hàm tìm kiếm tuyến tính .

INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

Số nguyên đầu tiên: số nguyên X cần tìm.
Số nguyên thứ hai: số lượng phần tử của mảng 1 chiều
Các số nguyên còn lại: giá trị của các phần tử của mảng
OUTPUT
Nếu tìm thấy, xuất true. Ngược lại xuất false.*/

#include <iostream>
#define MAXN 400000

using namespace std;

void NhapMang(int a[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int LinearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return -1;
}

int main() {
    int a[MAXN], n, x;

    std::cin >> x;

    NhapMang(a, n);

    int i= LinearSearch(a, n, x);

    if (i==-1) std::cout << "false";
    else std::cout << "true";
    return 0;
}
