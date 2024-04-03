#include "p13 CS211 - DSA - 20230503 ( Queue-linked ).h"
//#include<queue> // STL 

#include<iostream>

using namespace std;
int main()
{
	queue<int> s;
	
	s.push(10);
	s.push(20);
	
	cout<<"s: "<<s<<endl;
	cout<<"s has "<<s.size()<<" elements. "<<endl;
	
	queue<int> t;
	
	t.push(5);
	t.push(2);
	t.push(7);
	
	cout<<"\nt: "<<t<<endl;
	t=s;		// assignment operater invoked
	cout<<"t: "<<t<<endl;
	
	cout<<"\nEmptying s "<<endl;
	while(!s.empty())
	{
		cout<<s.front()<<" ";
		s.pop();
	}
	cout<<endl;
	
	queue<int> u=t; // copy constructer invoked. OR u(t).
 	
	
	cout<<"\nEmptying t "<<endl;
	while(!t.empty())
	{
		cout<<t.front()<<" ";
		t.pop();
	}
	cout<<endl;
	
	
	
	
	return 0;
}