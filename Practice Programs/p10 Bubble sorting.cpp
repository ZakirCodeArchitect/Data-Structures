#include<iostream>
using namespace std;


void bubble_sort(int arr[] , int n )
{
	for(int i=0; i<n-1 ; i++)	// It represents the number of passes or iterations required to sort the array.
	{
		for(int j=0; j<n-1;j++)		// It represents the comparison and swapping of adjacent elements during each pass.
		{
			if(arr[j] > arr[j+1])		// The swapping process continues until the inner loop completes, and the largest element in the unsorted portion of the array is moved to its correct position at the end.
			{
				int temp;
				
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}	//  the array is fully sorted in ascending order.
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
	
	bubble_sort(arr , size);
	
	cout<<"Array After sorting : "<<endl;
	for(int i=0; i<size ; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	
	return 0;
}