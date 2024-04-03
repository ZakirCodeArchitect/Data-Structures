#include "p10 CS211 - DSA - 20230417 ( stack-linked header ).h"
#include<stack>	//STL
#include<iostream>

using namespace std;

void f()
{
	stack<int> a,b;
}

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	
	cout<<"Emptying s"<<endl;
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}	
	
	cout<<endl;
	
	
	return 0;
		
		
}