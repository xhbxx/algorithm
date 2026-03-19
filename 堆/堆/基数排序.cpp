#include<iostream>
#include<string>
#include<vector>
#include<functional>
#include<stdlib.h>
#include<time.h>
using namespace std;

void RadixSort(int arr[], int size)
{
	int maxdata = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (maxdata < arr[i])
		{
			maxdata = arr[i];
		}
	}
	int len = to_string(maxdata).size();

	vector<vector<int>> vecs;
	int mod = 10;
	int dev = 1;
	for (int i = 0; i < len; mod *= 10, dev *= 10, i++)
	{
		vecs.resize(10);
		for (int j = 0; j < size; j++)
		{
			int index = arr[j] % mod / dev;
			vecs[index].push_back(arr[j]);
		}
		int idx = 0;
		for (auto vsc : vecs)
		{
			for (auto v : vsc)
			{
				arr[idx++] = v;
			}
		}
		vecs.clear();
	}
}

int main()
{
	time_t a = time(NULL);
	cout << a;
}