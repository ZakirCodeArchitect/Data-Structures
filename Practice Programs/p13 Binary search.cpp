#include<iostream>

using namespace std;

int binarySearch(int arr[] , int left , int right , int target)
{
	while(left <= right)
	{
		int mid = left + (right - left ) / 2;	// Finding the mid index.
		
		if(arr[mid] == target)
		{
			return mid;
		}
		
		if(arr[mid] < target)	// If the element at the mid index is less than the target, the left index is updated to mid + 1 to search in the right half of the array.
		{
			left  = mid + 1;
		}
		else		// If the element at the mid index is greater than the target, the right index is updated to mid - 1 to search in the left half of the array.
		{
			right = mid - 1;
		}
	}
	
	return -1;
}

int main() 
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter the element to search: ";
    cin >> target;

    int result = binarySearch(arr, 0, size - 1, target);

    if (result == -1) 
	{
        cout << "Element not found in the array." <<endl;
    } 
	else 
	{
        cout << "Element found at index " << result << "." <<endl;
    }

    return 0;
}