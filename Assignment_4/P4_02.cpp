/*Sắp xếp mảng một chiều các số nguyên tăng dần bằng phương pháp mergesort. Biết rằng số lượng phần tử của mảng <= 150,000; giá trị các phần tử < 1 tỷ.

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
#include <climits>
#define MAXN 150000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void merge(int input[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = input[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = input[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            {
                input[k] = L[i];
                i++;
            }
        else 
            {
                input[k] = R[j];
                j++;
            }
            k++;
    }

    while (i < n1)
    {
        input[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        input[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortRange(int input[], int from, int to) {
    if (from < to) {
        int middle = (from + to) / 2;
        mergeSortRange(input, from, middle);
        mergeSortRange(input, middle + 1, to);
        merge(input, from, middle, to);
    }
}

void mergeSort(int input[], int n) {
    mergeSortRange(input, 0, n - 1);
}

void XuatMang(int A[], const int &N) {
    // std::cout << is_ascending(A, N) << std::endl;
    std::cout << N << std::endl;
    for (int i = 0; i < N; i++)
        std::cout << A[i] << " ";
}


int main() {
    int a[MAXN], n;

    NhapMang(a, n);

    mergeSort(a, n);

    XuatMang(a, n);

    return 0;
}
