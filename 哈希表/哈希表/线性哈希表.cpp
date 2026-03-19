#include<iostream>

using namespace std;

enum State
{
	unuse,
	use,
	del,
};

struct bucket
{
	bucket(int key=0,State s=unuse) :key_(key), state(s) {};
	int key_;
	State state;

};
class hashtables
{	
public:
	hashtables(int size = pri_[0], double loadfactor = 0.75)
		:usenum(0)
		, loadfactor(loadfactor)
		, primeidx_(0)
	{
		if (size != 3)
		{
			for (; primeidx_ < 6; primeidx_++)
			{
				if (pri_[primeidx_] > size)
				{
					break;
				}
			}
		}
		tablesize_ = pri_[primeidx_];
		ta_ = new  bucket[tablesize_];
	}
	~hashtables()
	{
		delete[]ta_;
		ta_ = nullptr;
	}
public:
	bool insert(int key)
	{
		double factor = usenum*1.0 / tablesize_;
		cout << factor << endl;
		if (factor >= loadfactor)
		{
			expand();
		}
		int s_idx= key % tablesize_;
		int idx = s_idx;
		do
		{
			if (ta_[idx].state != use)
			{
				ta_[idx] = key;
				ta_[idx].state = use;
				usenum++;
				return true;
			}
			idx = (idx + 1) % tablesize_;
		} while (idx != s_idx);
		return false;
	}

	bool erase(int key)
	{
		int idx = key % pri_[primeidx_];
		int idx_s = idx;
		do
		{
			if (ta_[idx].state == use && ta_[idx].key_ == key)
			{
				
				ta_[idx].state = del;
				usenum--;
			}
			idx = (idx + 1) % tablesize_;
		} while (ta_[idx].state != unuse && idx != idx_s);
		return true;
	}
	
	int find(int key)
	{
		int idx = key % pri_[primeidx_];
		int idx_s = idx;
		do
		{
			if (ta_[idx].state == use && ta_[idx].key_ == key)
			{
				return true;
			}
			idx = (idx + 1) % tablesize_;
		} while (ta_[idx].state != unuse&&idx != idx_s);
		return false;
	}

private:
	void expand()
	{
		++primeidx_;
		if (primeidx_ == 5)
		{
			throw"is full";
		}
		bucket*p = new bucket[pri_[primeidx_]];
		
		for (int i = 0;i < tablesize_; i++)
		{
			
			if (ta_[i].state == use)
			{
				int idx = ta_[i].key_ % pri_[primeidx_];
				int x = idx;
				do {
					if (p[idx].state != use)
					{
						p[idx].key_ = ta_[i].key_;
						p[idx].state = use;
						break;
					}
					idx = (idx + 1) % pri_[primeidx_];
				} while (idx != x);
			}
		}
		delete[]ta_;
		ta_ = p;
		tablesize_ = pri_[primeidx_];
	}
private:
	bucket* ta_;
	double loadfactor;
	int tablesize_;
	int usenum;

	static const int psize = 6;
	static int pri_[psize];
	int primeidx_;
};
int hashtables::pri_[psize] = {3,7,23,47,97,251};
