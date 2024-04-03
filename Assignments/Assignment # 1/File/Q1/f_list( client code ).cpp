#include"forward_list.h"
#include<iostream>

using namespace std;

int main()
{
	forward_list<int> f;		// First forward list
	
	try
	{
		f.push_front(1);
		f.push_front(3);
		f.push_front(5);
		f.push_front(7);
	}
	catch(const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	cout<<"Number of elements in the Forward list : "<<f.size()<<endl;
	
	forward_list<int> x;		// second forward list
	
	try
	{
		x.push_front(1);
		x.push_front(3);
		x.push_front(7);
		x.push_front(9);
	}
	catch(const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	node<T> *Mdisplay = merge(f,x);		// merge
	
	cout<<"Merged lists : "<<Mdisplay<<endl;
	
	node<T> *rev = reverse(f);
	
	cout<<" Reversed list : "<<rev<<endl;
	
	cout<<" Sorted list : "<<sort(f)<<endl;
	return 0;
}

