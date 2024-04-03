#include<iostream>

using namespace std;

void insertion_sort(int arr[] , int size)
{
	for(int i=1; i<size;i++)
	{
		int key = arr[i];	// Inside the loop, the current element at index i is stored in a temporary variable called key. This element will be inserted into its correct position in the sorted portion of the array.
		int j = i-1;	// . This variable represents the index of the last element in the sorted portion of the array.
		
		while(j>=0 && arr[j] > key)		// A while loop is used to find the correct position for the element key in the sorted portion of the array.
		{
			arr[j+1] = arr[j];		// Inside the while loop, the element at index j is shifted one position to the right (arr[j+1] = arr[j]), effectively making space for the key element.
			j--;	// The index j is decremented (j--) to continue comparing with the previous element in the sorted portion.
		}
		
		arr[j+1] = key;		// After finding the correct position, the key element is inserted into its sorted position by assigning its value to arr[j+1].
	}
}

int main()
{
	int size;
	
	cout<<"Enter the size of the array : ";
	cin>>size;
	
	int arr[size];
	
	cout<<"Enter the elements in the array : \n"<<endl;
	for(int i=0; i < size ; i++)
	{
		cout<<"arr["<<i+1<<"] = ";
		cin>>arr[i];
	}
	cout<<endl;
	
	cout<<"Array Before sorting : "<<endl;
	for(int i=0; i<size ; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	insertion_sort(arr , size);
	
	cout<<"Array After sorting : "<<endl;
	for(int i=0; i<size ; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}