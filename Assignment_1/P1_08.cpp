
#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_last_occurrence(int a[], int n, int x)
{
    int result = -1;
    int left = 0, right = n -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (a[mid] <= x)
        {
            if (a[mid] == x) result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}
int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);

    cout << binary_search_last_occurrence(a, n, x);

    return 0;
}


