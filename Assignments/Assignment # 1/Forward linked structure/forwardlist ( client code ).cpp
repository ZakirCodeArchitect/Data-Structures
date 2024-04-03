#include"forwardlist.h"
#include<iostream>

using namespace std;

int main()
{
	f_list<int> f;
	
	try
	{
		f.push(1);
		f.push(2);
		f.push(3);
		f.push(4);
	}
	catch(const char *msg)
	{
		cout<<"Error : "<<msg<<endl;
	}
	
	cout<<"Number of elements in the Forward list : "<<f.size()<<endl;
	
	cout<<"Forward list : "<<f<<endl;
	
	f_list<int> w;
	w = f;
	
	cout<<"Forward list after copying : ";
	while(!w.empty())
	{
		cout<<w.front()<<" ";
		w.pop();
	}
	cout<<endl;
	
	
	
	return 0;
}