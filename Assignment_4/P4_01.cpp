/*Sắp xếp mảng một chiều các số nguyên tăng dần bằng phương pháp heapsort. Biết rằng số lượng phần tử của mảng <= 200,000; giá trị các phần tử < 1 tỷ.

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
#define MAXN 200000

void NhapMang(int A[], int &N) {
    std::cin >> N;
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void Heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;
    
    if (largest != i)
        {
            swap(a[i], a[largest]);
            Heapify(a, n, largest);
        }
}

void buildHeap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i);    
}

void HeapSort(int a[], int n) {
	int heapSize;
	heapSize = n;
	buildHeap(a, heapSize);
	for (int i = n - 1; i>0; i--) {
		swap(a[0], a[i]);
		heapSize -= 1;
		Heapify(a, heapSize, 0);
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

    HeapSort(a, n);

    XuatMang(a, n);

    return 0;
}
