#include<iostream>

using namespace std;

void selection_sort(int arr[], int size)
{
	for(int i=0; i<size-1 ; i++)	// During each iteration of the outer loop, the minimum element found in the unsorted portion of the array is placed at the current position i.
	{
		int minIndex = i;	// This variable keeps track of the index of the minimum element found during the inner loop.
		
		for(int j=i+1; j<size ; j++)	// It searches for the minimum element in the unsorted portion of the array.
		{
			if( arr[j] < arr[minIndex])		// In each iteration of the inner loop, an if condition compares the element at index j with the current minimum element at index minIndex
			{
				minIndex = j;		// After the inner loop completes, the minimum element in the unsorted portion of the array is found, and its index is stored in minIndex.
			}
		}
		
		// To swap the minimum element with the element at the current position i.
		
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
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
	
	selection_sort(arr , size);
	
	cout<<"Array After sorting : "<<endl;
	for(int i=0; i<size ; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}