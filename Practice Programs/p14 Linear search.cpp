#include<iostream>

using namespace std;

int linearSearch(int arr[], int size, int target) 
{
    for (int i = 0; i < size; i++) 
	{
        if (arr[i] == target) 
		{
            return i;  // Element found at index i
        }
    }
    return -1;  // Element not found
}

int main() 
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    std::cout << "Enter the element to search: ";
    std::cin >> target;

    int result = linearSearch(arr, size, target);

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