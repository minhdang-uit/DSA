/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword

Tìm vị trị cuối cùng chứa giá trị X trong mảng 1 chiều lưu n phần tử ( <=400,000) các số nguyên (< 2 tỷ). Nếu không tìm thấy xuất ra -1. Yêu cầu: Sử dụng hàm tìm kiếm nhị phân (không dùng đệ quy).

INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

Số nguyên đầu tiên: số nguyên X cần tìm.
Số nguyên thứ hai: số lượng phần tử của mảng 1 chiều
Các số nguyên còn lại: giá trị của các phần tử của mảng
OUTPUT
Xuất ra số nguyên chỉ vị trí cuối cùng xuất hiện X. Nếu không tìm thấy thì xuất -1.*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_greatestLesser_last_occurrence(int a[], int n, int x)
{
    int result = -1;
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) /2;
        if (a[mid] >= x) 
        {
            right = mid - 1;
        }
        else
        {
            result = mid;
            left = mid + 1;
        }
    }
    return result;
}
int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_greatestLesser_last_occurrence(a, n, x);

    return 0;
}



