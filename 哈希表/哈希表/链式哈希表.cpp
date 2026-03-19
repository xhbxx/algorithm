#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

class hashtable
{
public:
	hashtable(int size = 3, double fac = 0.75)
		:loadfactor(fac)
		, usenum_(0)
		, primeidx_(0)
	{
		if (size != pri_[0])
		{
			for (; primeidx_ < 6; primeidx_++)
			{
				if (pri_[primeidx_] > size)
				{
					break;
				}
			}
		}
		table_.resize(pri_[primeidx_]);
	}
public:
	void insert(int key)
	{
		double factor = usenum_ * 1.0 / table_.size();
		cout << factor << endl;
		if (factor > loadfactor)
		{
			expand();
		}
		int idx = key % pri_[primeidx_];
		if (table_[idx].empty())
		{
			usenum_++;
			table_[idx].emplace_front(key);
		}
		else
		{
			auto it = ::find(table_[idx].begin(), table_[idx].end(), key);
			if (it == table_[idx].end())
			{
				table_[idx].emplace_front(key);
			}
		}
	}

	void erase(int key)
	{
		int idx = key % pri_[primeidx_];
		auto it = ::find(table_[idx].begin(), table_[idx].end(), key);
		if (it != table_[idx].end())
		{
			table_[idx].erase(it);
			if (table_[idx].empty())
			{
				usenum_--;
			}
		}
	}
	bool find(int key)
	{
		int idx = key % pri_[primeidx_];
		auto it = ::find(table_[idx].begin(), table_[idx].end(), key);
		if (it != table_[idx].end())
		{
			return true;
		}
		return false;
	}
private:
	void expand()
	{
		if (primeidx_ + 1 == 6)
		{
			throw"is full";
		}
		primeidx_++;
		usenum_ = 0;
		
		vector<list<int>> old;
		table_.swap(old);
		table_.resize(pri_[primeidx_]);		
		for (auto list : old) 
		{
			for (auto key : list) 
			{

				int idx = key % pri_[primeidx_];
				if (table_[idx].empty())
				{
					usenum_++;
				}
				table_[idx].emplace_front(key);
			}
		}
	}
private:
	vector<list<int>> table_;
	int usenum_;
	double loadfactor;
	
	static const int psize = 6;
	static int pri_[psize];
	int primeidx_;
};
int hashtable::pri_[psize] = { 3,7,23,47,97,251 };

int main()
{
	hashtable h;
	h.insert(1);
	h.insert(12);
	
	h.insert(33);
	h.insert(41);
	
	h.erase(41);

	return 0;
}