/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/


#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10000;

void NhapMang(int a[], int &n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];	
}

void selection_sort_ascending(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;
		swap(a[i], a[min_idx]);
	}
}

bool is_ascending(int a[], int n)
{
	for (int i = 1; i < n; i++)
		if (a[i] < a[i-1])
			return false;
	return true;
}

int main() {
    int a[MAXN], n;

    std::cin >> n;

    NhapMang(a, n);

    selection_sort_ascending(a, n);

    std::cout << std::boolalpha << is_ascending(a, n);

    return 0;
}
