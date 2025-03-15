/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
/*Sắp xếp mảng một chiều các số nguyên sao cho số nguyên chẵn giảm dần.

INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

Số nguyên đầu tiên: số lượng phần tử của mảng
Các số nguyên còn lại: giá trị của các phần tử của mảng
 

OUTPUT
Mảng số nguyên đã được sắp xếp các số nguyên chẵn giảm dần

EXAMPLE
Input	Output
7
12
14
0
41
567
8
-545	14 12 8 41 567 0 -545*/


#include <bits/stdc++.h>
using namespace std;

#define MAXN 100

int Input()
{
    int x;
    cin >> x;
    return x;
}

void NhapMang(int A[], int N)
{
    for (int i = 0; i < N; i++)
        cin >> A[i];    
}

void SapXepSoChanGiamDan(int A[], int N)
{
    int chan[MAXN], k = 0;
    for (int i = 0; i < N; i++)
        if (A[i] % 2 == 0)
            chan[k++] = A[i];

    sort(chan, chan + k, greater<int>());
    
    int idx = 0;
    for (int i = 0; i < N; i++)
        if (A[i] % 2 == 0)
            A[i] = chan[idx++];
}
void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
}
int main() {
    int a[MAXN], n;
    n=Input();
    NhapMang(a, n);
    SapXepSoChanGiamDan(a, n);
    XuatMang(a, n);
    return 0;
}
