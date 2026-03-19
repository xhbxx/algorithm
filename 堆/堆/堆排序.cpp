#include<iostream>
#include<functional>
#include<stdlib.h>
#include<time.h>
using namespace std;

void siftdown(int arr[], int i, int size) 
{
	int val = arr[i];
	while (i < size / 2)
	{
		int son = 2 * i + 1;
		if (son+1<size&&arr[son + 1] > arr[son])
		{
			son += 1;
		}
		if (arr[son] > val)
		{
			arr[i] = arr[son];
			i = son;
		}
		else
		{
			break;
		}
	}
	arr[i] = val;
}
void heapSort(int arr[], int size)
{
	int n = size - 1;
	for (int i =( n-1)/2; i >= 0; i--)
	{
		siftdown(arr, i, size);
	}

	for (int i = n; i > 0; i--)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		siftdown(arr, 0, i);
	}
}

