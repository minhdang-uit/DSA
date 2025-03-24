/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword

Tìm giá trị X trong mảng 1 chiều lưu n phần tử ( n <= 150,000) các số nguyên (< 1 tỷ) GIẢM DẦN.

Yêu cầu: Viết hàm tìm kiếm tuyến nhị phân SỬ DỤNG ĐỆ QUY.

INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

Số nguyên đầu tiên: số nguyên X cần tìm.
Số nguyên thứ hai: số lượng phần tử của mảng 1 chiều
Các số nguyên còn lại: giá trị của các phần tử của mảng
OUTPUT
Xuất ra true nếu tìm thấy, false nếu không tìm thấy.*/

#include <iostream>

using namespace std;

bool binary_search(int a[], int left, int right, int x)
{
    int mid = left + (right - left) / 2;
    if (left > right) return 0;
    if (a[mid] == x) return 1;
    if (x < a[mid])
        return binary_search(a, mid + 1, right, x);
    else
        return binary_search(a, left, mid - 1, x);
}

int main() {
    int x; cin >> x;
    int n; cin >> n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << std::boolalpha << binary_search(a, 0, n-1, x);

    return 0;
}

