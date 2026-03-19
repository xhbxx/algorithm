#include <iostream>
using namespace std;

class seqstack
{
public:
	seqstack(int size = 10)
		:cap_(size)
		, top_(0)
	{
		stack_ = new int[cap_];
	}
	~seqstack()
	{
		delete[]stack_;
		stack_ = nullptr;
	}
public:
	void push(int val)
	{
		if (top_ == cap_)
		{
			expand(2 * cap_);
		}
		else
		{
			stack_[top_++] = val;
		}
	}
	void pop()
	{
		if (top_ == 0)
			throw"stack is empty";
			top_--;

	}
	int top() const
	{
		if (top_ == 0)
			throw "stack is empty";
		return stack_[top_-1];
	}
	bool empty() const { return top_ == 0;}
	int size() const { return top_; }
private:
	void expand(int val)
	{
		int* p = new int[val];
		memcpy(p, stack_, top_ * sizeof(int));
		delete[]stack_;
		stack_ = p;
		cap_ = val;
	}
private:
	int* stack_;
	int top_;
	int cap_;
};
