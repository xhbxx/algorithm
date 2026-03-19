#include <iostream>
#include <functional>
#include<stack>
#include<deque>
#include<vector>
#include"time.h"
#include<cmath>
using namespace std;

template<typename T>
class avltree
{
public:
	avltree() :root_(nullptr) {}

	void insert(const T& val)
	{
		root_ = insert(root_, val);
	}
	void remove(const T& val)
	{
		root_ = remove(root_, val);
	}

private:
	struct Node
	{
		Node(T data = T())
			:data_(data)
			, left_(NULL)
			, right_(NULL)
			, height_(1)
		{
		}
		T data_;
		Node* left_;
		Node* right_;
		int height_;
	};

	int height(Node* nod)
	{
		return nod == nullptr ? 0 : nod->height_;
	}

	Node* rightrotate(Node* nod)
	{
		Node* child = nod->left_;
		nod->left_ = child->right_;
		child->right_ = nod;
		nod->height_ = max(height(nod->left_), height(nod->right_)) + 1;
		child->height_ = max(height(child->left_), height(child->right_)) + 1;
		return child;
	}
	Node* leftrotate(Node* nod)
	{
		Node* child = nod->right_;
		nod->right_ = child->left_;
		child->left_ = nod;
		nod->height_ = max(height(nod->left_), height(nod->right_)) + 1;
		child->height_ = max(height(child->left_), height(child->right_)) + 1;
		return child;
	}

	Node* leftbalance(Node* nod)
	{
		nod->left_ = leftrotate(nod->left_);
		return rightrotate(nod);
	}
	Node* rightbalance(Node* nod)
	{
		nod->right_ = rightrotate(nod->right_);
		return leftrotate(nod);
	}

	Node* insert(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return new Node(val);
		}
		if (val > node->data_)
		{
			node->right_=insert(node->right_, val);
			if (height(node->right_) - height(node->left_) > 1)
			{
				if (height(node->right_->right_) >= height(node->right_->left_))
				{
					node=leftrotate(node);
				}
				else
				{
					node = rightbalance(node);
				}
			}
		}
		else if(val <node->data_)
		{
			node->left_=insert(node->left_, val);
			
			if (height(node->left_) - height(node->right_) > 1)
			{
				if (height(node->left_->left_) >= height(node->left_->right_))
				{
					node = rightrotate(node);
				}
				else
				{
					node = leftbalance(node);
				}
			}
		}
		else
		{
			;
		}
		node->height_ = max(height(node->right_), height(node->left_)) + 1;
		return node;
	}
	Node* remove(Node* node, const T& val)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (node->data_ > val)
		{
			node->left_ = remove(node->left_, val);
			if (height(node->right_) - height(node->left_) > 1)
			{
				if (height(node->right_->right_) >= height(node->right_->left_))
				{
					node = leftrotate(node);
				}
				else
				{
					node = rightbalance(node);
				}

			}
		}
		else if (node->data_ < val)
		{
			node->right_ = remove(node->right_, val);
			if (height(node->left_) - height(node->right_) > 1)
			{
				if (height(node->left_->left_) >= height(node->left_->right_))
				{
					node = rightrotate(node);
				}
				else
				{
					node = leftbalance(node);
				}
			}
		}

		else
		{
			if (node->right_ != nullptr && node->left_ != nullptr)
			{
				if (height(node->left_) >= height(node->right_))
				{
					Node* pre = node->left_;
					while (pre->right_ != nullptr)
					{
						pre = pre->right_;
					}
					node->data_ = pre->data_;
					node->left_ = remove(node->left_, pre->data_);
				}
				else
				{
					Node* post = node->right_;
					while (post->left_ != nullptr)
						post = post->left_;
					node->data_ = post->data_;
					node->right_ = remove(node->right_, post->data_);
				}
			}
			else
			{
				if (node->left_ != nullptr)
				{
					Node* left = node->left_;
					delete node;
					return left;
				}
				else if (node->right_ != nullptr)
				{
					Node* right = node->right_;
					delete node;
					return right;
				}
				else
				{
					return nullptr;
				}
			}
		}
		node->height_ = max(height(node->right_), height(node->left_)) + 1; 
		return node;
	}
private:
	Node* root_;
};
