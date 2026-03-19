#include<iostream>
#include<functional>
#include<stdlib.h>
#include<time.h>
using namespace std;

class priorityqueue
{
public:
	using camp = function<bool(int, int)>;
public:
	priorityqueue(int cap = 10, camp ca = greater<int>())
		:size_(0)
		, cap_(cap)
		, ca_(ca)
	{
		que_ = new int[cap_];
	}
	/*priorityqueue( camp ca = greater<int>())
		:size_(0)
		, cap_(20)
		, ca_(ca)
	{
		que_ = new int[cap_];
	}*/
	~priorityqueue()
	{
		delete[] que_;
		que_ = nullptr;
	}
public:
	void push(int val)
	{
		if (size_ == cap_)
		{
			int* p = new int[cap_ * 2];
			for (int i = 0; i <= size_; i++)
			{
				p[i] = que_[i];
			}
			delete[] que_;
			que_ = p;
			cap_ *= 2;
		}
		if (size_ == 0)
		{
			que_[size_] = val;
		}
		else
		{
			siftUp(size_,val);
		}
		size_++;
	}

	void pop()
	{
		if (size_ == 0)
			throw"is empty";
		size_--;
		if (size_ > 0)
		{
			siftDown(0,que_[size_]);
		}
	}

	bool empty() const { return size_ == 0; }

	int top() const
	{
		if (size_ == 0)
			throw"is empty";
		return que_[0];
	}

	int size() const { return size_; }
private:
	void siftUp(int i, int val)
	{
		while (i > 0)
		{
			int father = (i - 1) / 2;
			if (ca_(val, que_[father]))
			{
				que_[i] = que_[father];
				i = father;
			}
			else
			{
				break;
			}
		}
		que_[i] = val;
	}

	void siftDown(int i,int val)
	{
		while (i < size_/2)
		{
			int son = i * 2 + 1;
			if (son + 1 < size_ && ca_(que_[son + 1], que_[son]))
			{
				son = son + 1;
			}
			if (ca_(que_[son], val))
			{
				que_[i] = que_[son];
				i = son;
			}
			else
			{
				break;
			}
		}
		que_[i] = val;
	}

private:
	int* que_;
	int size_;
	int cap_;
	camp ca_;
};

