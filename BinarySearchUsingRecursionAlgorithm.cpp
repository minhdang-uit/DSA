/* Suppose we have an array M consisting of N elements.
The problem is to determine whether there exists an element with a value equal to X in array M.
If such an element exists, at which position in array M is it located?
(BinarySearch using Recursion Algorithm) */

#include <bits/stdc++.h>

using namespace std;

// Recursive Binary Function
// Hàm tìm kiếm nhị phân bằng đệ quy
int BinarySearchRecursive(const vector<int> &Array, int left, int right, int target)
{
    if (left > right) //not found | Không tìm thấy
        return -1;

    int mid = left + (right - left) / 2; 

    if (Array[mid] == target) 
        return mid;
    if (Array[mid] > target)
        return BinarySearchRecursive(Array, left, mid - 1, target);
    
        return BinarySearchRecursive(Array, mid + 1, right, target);    
}
//find all occurences of target
//Tìm tất cả vị trí xuất hiện của số cần tìm
vector<int> FindAllOccurrences(const vector<int> &Array, int target)
{
    vector<int> result;
    int index = BinarySearchRecursive(Array, 0, Array.size()-1, target);

    if (index == -1) return result; //not found | không tim thấy

    //Expand to the left to find all occurrences
    //Tìm kiếm ở nửa bên trái
    int left = index;
    while (left >= 0 && Array[left] == target)
    {
        result.push_back(left);
        left--;
    }

    //Expand to the right to find all occurrences
    //Tìm kiếm ở nửa bên phải
    int right = index + 1;
    while (right < Array.size() && Array[right] == target)
    {
        result.push_back(right);
        right++;
    }
    sort(result.begin(), result.end());
    return result;
}

int main()
{
    int size;
    cout << "Enter the size of the Array: ";
    cin >> size;

    vector<int> Array(size);
    cout << "Enter the elements of the Array: ";
    for (int i = 0; i < size; i++)
        cin >> Array[i];

    int UserValue;
    cout << "Enter the number to search for: ";
    cin >> UserValue;

    //Sort the binary | Sắp xếp mảng 
    sort(Array.begin(), Array.end());

    cout << "The Sorted Array: ";
    for (int i = 0; i < Array.size(); i++)
        cout << Array[i] << " ";
        cout << endl;

    vector<int> positions = FindAllOccurrences(Array, UserValue);

    if (!positions.empty())
    {
        cout << "The number " << UserValue << " was found at positions: ";
        for (int idx : positions)
            cout << idx << " ";
    }
    else
    {
        cout << "The number " << UserValue << " was not found.";
    }
}

/*
Time complexity:
Overall Time Complexity:
-> Sorting: O(N log N)
-> BinarySearch: O(log N)
-> Finding all occurences: O(K)
---> O(N log N) + O(log N) + O(K) = O(N log N) + O(K)
If K is small:
-> Best case: O(N log N)
-> Worst case: O(N log N)
-> Average case: O(N log N)
*/
