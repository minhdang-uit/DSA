/*Sắp xếp mảng sao cho: đứng đầu mảng là các số dương giảm dần, kế đến là các số âm tăng dần, cuối cùng là các số 0.

INPUT
Dãy các số trong đó: (Giả sử luôn thỏa điều kiện nhập)

Số nguyên đầu tiên: số lượng phần tử của mảng
Các số nguyên còn lại: giá trị của các phần tử của mảng
OUTPUT
Mảng số nguyên đã được sắp xếp trong đó: đứng đầu mảng là các số dương giảm dần, kế đến là các số âm tăng dần, cuối cùng là các số 0.*/

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include<iostream>

void XuatMang(int A[], int N) {
    for (int i = 0; i < N; i++)
        std::cout << A[i] << '\t';
    std::cout << std::endl;
}
#include <vector>
#include <algorithm>
using namespace std; 
#define MAXN 100000
void NhapMang(int A[], int &n) {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
}

void SapXepSoDuongGiamAmTangVa0(int A[], int n) {
    vector <int> arr_pos, arr_neg, arr_zero;
    for (int i = 0; i < n; i++) { 
        if (A[i] < 0) {
            arr_neg.push_back(A[i]); 
            continue; 
        }
        if (A[i] > 0) {
            arr_pos.push_back(A[i]);
            continue; 
        }
        arr_zero.push_back(A[i]); 
    }
    sort(arr_pos.begin(), arr_pos.end(), greater<int>());
    sort(arr_neg.begin(), arr_neg.end());
    int id = 0; 
    for (int i = 0; i < (int)arr_pos.size(); i++) A[id++] = arr_pos[i]; 
    for (int i = 0; i < (int)arr_neg.size(); i++) A[id++] = arr_neg[i]; 
    for (int i = 0; i < (int)arr_zero.size(); i++) A[id++] = arr_zero[i];  
}

int main() {
    int a[MAXN], n;
    NhapMang(a, n);
    SapXepSoDuongGiamAmTangVa0(a, n);
    XuatMang(a, n);
    return 0;
}
