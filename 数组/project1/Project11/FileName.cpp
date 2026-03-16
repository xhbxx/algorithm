#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

class marray 
{
public:
	marray(int size = 10) :mcur(0), mcap(size) {
		mparr = new int[mcap]();
	}
	~marray()
	{
		delete[]mparr;
		mparr = nullptr;
	}
	void push_back(int val)//0(n)
	{
		if (mcur == mcap)
		{
			expand(2 * mcap);//O(n)
		}
		mparr[mcur++] = val;//O(n)
	}
	void pop_back()//O(1)
	{
		if (mcur == 0)
		{
			return;
		}
		mcur--;
	}
	void insert(int pos, int val)//O(n)
	{
		if (pos<0 || pos>mcur)
		{
			return;
		}
		if (mcur == mcap)
		{
			expand(2 * mcap);
		}
		for (int i =pos; i >= pos; i--)
		{
			int temp = mparr[i];
			mparr[i] = mparr[i + 1];
		    mparr[i + 1] = temp;
		}
		mparr[pos] = val;
		mcur++;
	}
	void erase(int pos)//O(n)
	{
		if (pos > mcur || pos < 0)
		{
			return;
		}
		for (int i = pos ; i < mcur; i++) {
			mparr[i] = mparr[i+1];
		}
		mcur--;
	}
	int find(int val)//O(n)
	{
		for (int i = 0; i < mcur; i++) 
		{
			if (mparr[i] == val)
			{
				return i;
			}
		}
		return -1;
	}	
	void show()const
	{
		for (int i = 0; i < mcur; i++)
		{
			cout << mparr[i] << "  ";
		}
		cout << endl;
	}
private:
	void expand(int size)
	{
		int* p = new int[size];
		memcpy(p, mparr, sizeof(int) * mcap);
		delete[]mparr;
		mparr = p;
		mcap = size;
	}
private:
	int *mparr;
	int mcap;
	int mcur;

};
int main() 
{
	marray arr;
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand()%100);
	}
	arr.show();
	arr.pop_back();
	arr.show();
	arr.insert(3, 111);
	arr.show();
	arr.erase(3);
	arr.show();
	arr.erase(arr.find(24));
	arr.show();

}