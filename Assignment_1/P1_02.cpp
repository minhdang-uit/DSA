/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
goto
###End banned keyword

Tìm giá trị X trong mảng 1 chiều lưu n phần tử ( n <=150,000) các số nguyên (< 1 tỷ) TĂNG DẦN. Xuất ra true nếu tìm thấy, false nếu không tìm thấy. Yêu cầu: Viết hàm tìm kiếm tuyến nhị phân KHÔNG SỬ DỤNG ĐỆ QUY.

INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

Số nguyên đầu tiên: số nguyên X cần tìm.
Số nguyên thứ hai: số lượng phần tử của mảng 1 chiều
Các số nguyên còn lại: giá trị của các phần tử của mảng
OUTPUT
Xuất ra true nếu tìm thấy, false nếu không tìm thấy.*/

#include <iostream>

using namespace std;

bool binary_search(int *a, int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left)/2;
        if (a[mid] == x) return 1;
        if (a[mid] > x)
            right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int main() {
    int x; cin >> x;
    int n; cin >> n;

    int *a=new int[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << std::boolalpha << binary_search(a, 0, n-1, x);;

    return 0;
}


