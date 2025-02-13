/* Giả sử chúng ta có một mảng M gồm N phần tử.
 Vấn đề đặt ra là có hay không phần tử có giá trị bằng X trong mảng M?
 Nếu có thì phần tử có giá trị bằng X là phần tử thứ mấy trong mảng M? */

 #include <bits/stdc++.h>
 
 using namespace std;

 vector<int> LinearSearching(vector<int> Array, int SearchValue)
{
    vector<int> indices;
    for (int i = 0; i < Array.size(); i++)
        if (Array[i] == SearchValue)
        indices.push_back(i);
    return indices;
}

int main()
{
    //Enter the size of the Array
    int size;
    cin >> size;

    //Enter the elements of the Array
    vector<int> Array(size);
    for (int i = 0; i < size; i++)
        cin >> Array[i];

    //Input the value to search for
    int UserValue;
    cout << "Enter an integer to search: ";
    cin >> UserValue;

    //Call the LinearSearching Function
    vector<int> result = LinearSearching(Array, UserValue);

    //Print the result
    if (!result.empty())
    {
        cout << "The number " << UserValue << " was found at indices: ";
        for (int idx : result)
            cout << idx << " ";
    }
    else 
    {
        cout << "The number " << UserValue << " was not found." << endl;
    }
}