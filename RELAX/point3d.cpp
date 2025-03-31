#include <bits/stdc++.h>

using namespace std;

const int N = 10e6;

struct Point
{
    int x;
    int y;
    int z;
} A[N];

bool compare(Point x, Point y)
{
    if (x.x ==  y.x) {
        if (x.y == y.y) return x.z < y.z; 
        return x.y > y.y; 
    }
    return x.x < y.x;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i].x >> A[i].y >> A[i].z;

    sort(A, A + n, compare);

    for (int i = 0; i < n; i++)
        cout << A[i].x << " " << A[i].y << " " << A[i].z << endl;

}
