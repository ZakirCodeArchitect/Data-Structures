#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	string name;
	
	fstream f;
	f.open("task1.txt", ios::in );
	if(!eof)
	{
		cout<<"Failed to open file "<<endl;
	}
	
	while(!f.eof())
	{
		getline(f,name,'\n');
		cout<<name;
	}
	
	
	f.close();
	
	return 0;
	
}