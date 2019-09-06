#include<bits/stdc++.h>
using namespace std;
void binarysearch(int array[],int size,int num)
{
	int begin=0;
	int end=num;

	while(begin<=end)
	{        int mid=begin+(end-begin)/2;
		if(array[mid]==num)
			cout<<array[mid];
		if(array[mid]<num)
		{
			begin=mid+1;
		}
		else
		{
			end=mid-1;
		}
	
	}

}
int main()
{
	int size;
	cin>>size;
	int array[size];
	for(int i=0;i<size;i++)
	{
		cin>>array[i];

	}
	cout<<"Enter Element that you want to search";
	int findnum;
	cin>>findnum;
	sort(array,array+size);
	binarysearch(array,size,findnum);
}
