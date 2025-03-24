/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
while
goto
###End banned keyword
Tìm giá trị X trong mảng 1 chiều lưu n phần tử ( <=400,000) các số nguyên (< 2 tỷ). Xuất ra true nếu tìm thấy, false nếu không tìm thấy. Yêu cầu: Viết hàm tìm kiếm nhị phân (dùng đệ quy).

INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

Số nguyên đầu tiên: số nguyên X cần tìm.
Số nguyên thứ hai: số lượng phần tử của mảng 1 chiều
Các số nguyên còn lại: giá trị của các phần tử của mảng
 

OUTPUT
Nếu tìm thấy, xuất true. Ngược lại xuất false.*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

bool binary_search(int A[], int left, int right, int x)
{
    int mid = (left + right) / 2;
    if (left > right) return 0;
    if (A[mid] == x) return 1;
    if (x > A[mid])
        return binary_search(A, mid + 1, right, x);
    else
        return binary_search(A, left, mid - 1, x);
}
int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << boolalpha << binary_search(a, 0, n-1, x);

    return 0;
}
