/* Suppose we have an array M consisting of N elements.
The problem is to determine whether there exists an element with a value equal to X in array M.
If such an element exists, at which position in array M is it located?
(Regular Linear Searching) */

#include <bits/stdc++.h>
 
using namespace std;

vector<int> LinearSearching(vector<int> Array, int SearchValue)
{
   vector<int> positions; //Stores the positions where SearchValue is found.

   //Iterate Through the Array Using a FOR Loop
   for (int i = 0; i < Array.size(); i++)
       if (Array[i] == SearchValue)
       positions.push_back(i);
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

   //Input the value to search for
   int UserValue;
   cout << "Enter an integer to search: ";
   cin >> UserValue;

   //Call the LinearSearching Function
   vector<int> result = LinearSearching(Array, UserValue);

   //Print the result
   if (!result.empty()) // Check if the 'result' list is not empty (meaning the number was found)
   {
       cout << "The number " << UserValue << " was found at indices: ";
       for (int idx : result) // Iterate through each element in the 'result' list
           cout << idx << " "; // Print the index of each occurrence
   }
   else // If the 'result' list is empty (meaning the number was not found)
   {
       cout << "The number " << UserValue << " was not found." << endl; // Print a message indicating that the number was not found in the list
   }
}
/*
Time Complexity:
-> Best case: O(1) if the element is found at the beginning.
-> Average case: 𝑂(𝑁).
-> Worst case: O(N) if the element is not in the array or is at the last position
*/

/*
Stoping Condition:
-> Checks each element and also verifies if it has reached the end of the list.
*/
/*\
Performance:
-> Requires two checks in each iteration (value comparison + boundary check).
*/


