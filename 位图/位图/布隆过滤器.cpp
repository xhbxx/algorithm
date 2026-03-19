#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<memory>
#include<stringhash.h>
using namespace std;

class bloomfilter
{
public:
	bloomfilter(int bitsize=1471)
		:bitsize_(bitsize)
	{
		bitmap_.resize(bitsiz_ / 32 + 1);
	}
public:
	void setbit(const char* str)
	{
		
	}
private:
	int bitsize_;
	vector<int> bitmap_;
};

