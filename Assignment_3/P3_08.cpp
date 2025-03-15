/*Sắp xếp mảng một chiều gồm n (0≤n≤100) các số nguyên sao cho số nguyên âm tăng dần.

INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

Số nguyên đầu tiên: số lượng phần tử của mảng
Các số nguyên còn lại: giá trị của các phần tử của mảng
 

OUTPUT
Mảng số nguyên đã được sắp xếp các số nguyên âm tăng dần*/
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

void NhapMang(int A[], int& n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
}

void SapXepSoAmTangDan(int A[], int n)
{
    int am[MAXN];
    int k = 0;
    for (int i = 0; i < n; i++)
        if (A[i] < 0)
            am[k++] = A[i];

    sort(am, am + k);
    
    int idx = 0;
    for (int i = 0; i < n; i++)
        if (A[i] < 0)  
            A[i] = am[idx++];
}
void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
}
int main() {
    int a[MAXN], n;
    NhapMang(a, n);
    SapXepSoAmTangDan(a, n);
    XuatMang(a, n);
    return 0;
}
