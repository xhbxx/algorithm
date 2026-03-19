#include<iostream>

using namespace std;

template<typename T>
class AVL
{
public:

private:
	struct Node
	{
		Nodee(T data = T())
			:data_(data)
			,left_(NULL)
			,right_(NULL)
			,height(1)
		{}
		T data_;
		Node* left_;
		Node* right_;
		int height_;
	 };

	Node* rightrotate(Node* node)
	{
		Node* child = node->left_;

	}

	Node* root_;
}

int main()
{


	return 0;
}