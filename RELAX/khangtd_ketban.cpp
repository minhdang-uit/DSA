#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector <int> a[N];
int l_x, r_x, l_y, r_y;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 2; i < n; i++) {
		a[i].push_back(i - 1);
		a[i].push_back(i + 1);
	}
	a[1].push_back(n);
	a[1].push_back(2);
	a[n].push_back(n - 1);
	a[n].push_back(1);
	while (m--) {
		/// right: 0, left: 1
		int x, y;
		cin >> x >> y;
		r_x = a[x][0];
		l_x = a[x][1];
		a[r_x][1] = l_x;
		a[l_x][0] = r_x;
		l_y = a[y][1];
		a[y][1] = x;
		a[l_y][0] = x;
		a[x][1] = l_y;
	}
	int tmp = a[1][1];
	cout << 1 << ' ';
	while (tmp != 1) {
		cout << tmp << ' ';
		tmp = a[tmp][1];
	}
}
