#include<iostream>
#define max_size 100

using namespace std;

void mergeSort(int a[], int beg1, int end2);
void merge(int a[], int beg1, int end1, int end2);

int main()
{
	int n, a[max_size];
	
	cout << "\nEnter array size : " ;
	cin >> n;
	
	cout << "\nEnter array : ";
	for(int i=0; i<n; i++)
		cin >> a[i];
		
	mergeSort(a, 0, n-1);
	cout << "\nSorted array : ";
	for(int i=0; i<n; i++)
		cout << a[i] << " " ;

return 0;
}

void mergeSort(int a[], int beg1, int end2)
{
	int end1 = (beg1+end2)/2;
	if(beg1 < end2)
	{
		mergeSort(a, beg1, end1);
		mergeSort(a, end1+1, end2);
		merge(a, beg1, end1, end2);
	}
}

void merge(int a[], int beg1, int end1, int end2)
{
	int size1 = end1 - beg1 + 1;
	int size2 = end2 - end1;
	
	int l[size1], r[size2];
	
	for(int i=0; i<size1; i++)
		l[i] = a[beg1+i];
	
	for(int i=0; i<size2; i++)
		r[i] = a[end1+i+1];
		
	int k=beg1, k1=0, k2=0;
	
	while(k1<size1 && k2<size2)
	{
		if(l[k1] < r[k2])
		{
			a[k] = l[k1++];
		}
		else
		{
			a[k] = r[k2++];
		}
		k++;
	}
	
	while(k1<size1)
	{
		a[k++] = l[k1++];
	}
	
	while(k2<size2)
	{
		a[k++] = r[k2++];
	}
		
}
