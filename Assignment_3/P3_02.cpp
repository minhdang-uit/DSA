/*Sắp xếp mảng một chiều các số nguyên giảm dần bằng phương pháp selection sort. Biết rằng số lượng phần tử của mảng <= 30,000; giá trị các phần tử < 1 tỷ.

INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

Số nguyên đầu tiên: số lượng phần tử của mảng
Các số nguyên còn lại: giá trị của các phần tử của mảng
OUTPUT
Xuất trên 2 dòng liền kề nhau:
- Dòng 1: Xuất số lượng phần tử mảng
- Dòng 2: Xuất danh sách đã được sắp xếp, mỗi phần tử cách nhau 1 khoảng trắng. Nếu mảng rỗng thì dòng này trống*/
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


#include <iostream>
#define MAXN 100000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}
void hoanvi(int &x, int &y){
    int temp=x;
    x=y;
    y=temp;
}

void selection_sort_decending(int A[], int &N)
{
    bool swapped;
    for (int i = 0; i < N-1; i++)
    {
        int max_idx = i;
        swapped = false;
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] > A[max_idx])
                max_idx = j;
                swapped = true;
        }
        if (swapped) 
            hoanvi(A[i], A[max_idx]);
    }
}

void XuatMang(int A[], const int &N) {
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}

int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    selection_sort_decending(a, n);

    XuatMang(a, n);

    return 0;   
}
