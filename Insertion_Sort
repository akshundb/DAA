#include<iostream>

using namespace std;
void insertionSort(int a[], int n);
int main()
{
	int n;
	
	cout<<"Enter array size :";
	cin>>n;
		
	cout<<"\nEnter array : ";
	
	int a[n];
	
	for(int i=0; i<n; i++)
	{
		cin>> a[i];
	}
	
	insertionSort(a,n);
	
	cout<<"\nSorted array : ";
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";

return 0;		
}

void insertionSort(int a[], int n)
{
	int i,key;
	for(int j=1; j<n; j++)
	{
		key = a[j];
		
		i = j-1;
		
		while(i>=0 && a[i]>key)
		{
			a[i+1] = a[i];
			i--;
		}
	a[i+1] = key;
	}
}
