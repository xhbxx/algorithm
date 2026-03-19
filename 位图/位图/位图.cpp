#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<memory>
using namespace std;

int main()
{
	vector<int> vec{ 13,19,55,1,2,69,4,12 };
	//定义位图数组 找最大值
	int* bitmap = new int[69 / 32 + 1]();
	unique_ptr<int> ptr(bitmap);

	for (auto key:vec)
	{
		int idx = key / 32;
		int num = key % 32;
		if ((bitmap[idx] & (1 << num)) == 0)
		{
			bitmap[idx] |= (1 << num);
		}
		else
		{
			cout << "repeat" << endl;
			return 0;
		}
	}

}