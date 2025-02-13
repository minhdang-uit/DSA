/* Suppose we have an array M consisting of N elements.
The problem is to determine whether there exists an element with a value equal to X in array M.
If such an element exists, at which position in array M is it located?
(Linear Searching with Sentinel Technique) */

 #include <bits/stdc++.h>

 using namespace std;

 vector<int> LinearSearchingPlus(vector<int> Array, int SearchValue)
 {
    Array.push_back(SearchValue); //Add SearchValue to the End of the Array

    vector<int> positions; //Stores the indices where SearchValue is found.

    int index = 0; //Keeps track of the current position in the array.

    //Iterate Through the Array Using a while Loop
    while (index < Array.size() - 1)
    {
        if (Array[index] == SearchValue)
            positions.push_back(index);
        index++;
    }

    //Remove the Extra Element Added at the End
    Array.pop_back(); 

    //Return the List of Found Positions
    return positions; 
 }

 int main()
 {
    //Enter the size of the Array
    int size;
    cout << "Enter the size of the Array: ";
    cin >> size;

    //Enter the elements of the Array
    vector<int> Array(size);
    cout << "Enter the elements of the Array: ";
    for (int i = 0; i < size; i++)
        cin >> Array[i];
    
    //Enter the Number to search for
    int UserValue;
    cout << "Enter the number to search for: ";
    cin >> UserValue;
    
    //Call the LinearSearchingPlus Function
    vector<int> results = LinearSearchingPlus(Array, UserValue);

    //Display the output
    if (!results.empty())
    {
        cout << "The number " << UserValue << " was found at indices: ";
        for (int idx : results)
            cout << idx << " ";
    }
    else 
    {
        cout << "The number " << UserValue << " was not found." << endl;
    }

 }
/*
Time Complexity:
-> Best case: O(1) if the element is found at the beginning.
-> Average case: 𝑂(𝑁).
-> Worst case: O(N) if the element is not in the array or is at the last position
*/
 
