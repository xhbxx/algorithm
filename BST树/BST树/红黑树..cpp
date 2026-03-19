#include <iostream>
#include <functional>
#include<stack>
#include<deque>
#include<vector>
#include"time.h"
#include<cmath>
using namespace std;

template<typename T>
class rbtree
{
public:
	rbtree() :root_(nullptr) {}
	
	void insert(const T& val)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return;
		}
		
		Node* parent = nullptr;
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ > val)
			{
				parent = cur;
				cur = cur->right_;
			}
			else if (cur->data_ < val)
			{
				parent = cur;
				cur = cur->left_;
			}
			else
			{
				return;
			}
		}
		Node* node = new Node(val,parent,nullptr,nullptr,RED);
		if (parent->data_ > val)
		{
			parent->left_ = node;
		}
		else
		{
			parent->right_ = node;
		}
		if (RED==color(parent))
		{
			fixafterinsert(node);
		}
		
		
	}
	void remove(const T& val)
	{
		if (root_ == nullptr)
		{
			return;
		}
		Node* cur = root_;
		while (node!=root_&& -cur != nullptr)
		{
			if (cur->data_ > val)
			{
				cur = cur->right_;
			}
			else if (cur->data_ < val)
			{
				cur = cur->left_;
			}
			else
			{
				break;
			}
		}
		if (cur == nullptr)
		{
			return;
		}
		if (cur->left_ != nullptr && cur->right_ != nullptr)
		{
			Node* pre = cur->left_;
			while (pre->right_ != nullptr)
			{
				pre = pre->right_;
			}
			cur->data_ = pre->data_;
			cur = pre;
		}
		Node* child = cur->left_;
		if (child == nullptr)
		{
			child = cur->right_;
		}
		if (child != nullptr)
		{
			child->parent_ = cur->parent_;
			if (cur->parent_ == nullptr)
			{
				root_ = child;
			}
			else
			{
				if (cur->parent_->left_ == cur)
					cur->parent_->left_ = child;
				else
					cur->parent_->right_ = child;
			}
			Color c = color(cur);
			delete cur;

			if (c == BLACK)
			{
				fixagterRemove(child);
			}
		}
		else//child==null
		{
			if (cur->parent_ == nullptr)
			{
				delete cur;
				root_ = nullptr;
				return;
			}
			else
			{
				if (color(cur) == BLACK)
				{
					fixafterRemove(cur);
				}
				else
				{
					if (cur->parent_->right_ == cur)
					{
						cur->parent_->right_ == nullptr;
					}
					else
					{
						cur->parent_->left_ == nullptr;
					}
					delete cur;
				}
			}
		}
	}
private:
	enum Color
	{
		BLACK,
		RED
	};
	struct Node
	{
		Node(T data = T(), Node* parent = nullptr, Node* left_ = nullptr, Node* right_ = nullptr, Color color = BLACK)
			:data_(data)
			, left_(left)
			, right_(right)
			, color_(color) 
		{ }
		T data_;
		Node* left_;
		Node* right_;
		Node* parent_;
		Color color_;
	
	};

	Color color(Node* node)
	{
		return node == nullptr ? BLACK : node->color_;
	}
	void setColor(Node* node, Color color)
	{
		node->color_ = color;
	}

	Node* left(Node* node) { return node->left_; }
	Node* right(Node* node) { return node->right_; }
	Node* parent(Node* node)
	{
		return node->parent_;
	}

	void leftrotate(Node* node)
	{
		Node* child = node->right_;
		child->parent_ = node->parent_;
		if (node->parent_ == nullptr)
		{
			root_ = child;
		}
		else
		{
			if (node->parent_->left == node)
			{
				node->parent_->left_ = child;
			}
			else
			{
				node->parent_->right_ = child;
			}
		}
		node->right_=child->left_;
		if (child->left_ != nullptr)
		{
			child->left_->parent_ = node;
		}
		child->left_ = node;
		node->parent_ = child;
	}
	void rightrotate(Node* node)
	{
		Node* child = node->left_;
		child->parent_ = node->parent_;
		if (node->parent_ == nullptr)
		{
			root_ = child;
		}
		else
		{
			if (node->parent_->left_ == node)
			{
				node->parent_->left_ = child;
			}
			else
			{
				node->parent_->right_ = child;
			}
		}
		node->left_ = child->right_;
		if (child->right_ != nullptr)
		{
			child->right_->parent_ = node;
		}
		child->right_ = node;
		node->parent_ = child;
	}

	void fixafterinsert(Node* node)
	{
		while (color(parent(node)) == RED)
		{
			if (left(parent(parent(node))) == parent(node))
			{
				Node* uncle = right(parent(parent(node)));
				if (RED == color(uncle))
				{
					setcolor(parent(node), BLACK);
					setcolor(uncle, BLACK);
					setcolor(parent(parent(node)), RED);
					node = parent(parent(node));
				}
				else
				{
					if (right(parent(node)) == node)
					{
						node = node->parent_;
						leftrotate(node);
					}
					setcolor(parent(node), BLACK);
					setcolor(parent(node), RED);
					rightrotate(parent(parent(node)));
					break;
				}
			}
			else
			{
				Node* uncle = left(parent(parent(node)));
				if (RED == color(uncle))
				{
					setcolor(parent(node), BLACK);
					setcolor(uncle, BLACK);
					setcolor(parent(parent(node)), RED);
					node = parent(parent(node));
				}
				else
				{
					if (left(parent(node)) == node)
					{
						node = node->parent_;
						rightrotate(node);
					}
					setcolor(parent(node), BLACK);
					setcolor(parent(node), RED);
					leftrotate(parent(parent(node)));
					break;
				}
			}
		}

		setcolor(root_, BLACK);
	}
	void fixafterRemove(Node* node)
	{
		while (color(node) == BLACK)
		{
			if (left(parent(node)) == node)
			{
				Node* brother = right(parent(node));
				if (color(brother) == RED)
				{
					setcolor(parent(node),RED);
					setcolor(brother, BLACK);
					leftrotate(parent(node));
					brother = right(parent(node));
				}
				if (color(brother->left_) == BLACK && color(brother->right_) == BLACK)
				{
					setcolor(brother, RED);
					node = parent(node); 
				}
				else
				{
					if (color(brother->right_)!=RED)
					{
						setcolor(brother, RED);
						setcolor(brother -> left_, BLACK);
						rightrotate(brother);
						brother = parent(node)->right_;
					}
					setcolor(brother, color(parent(node)));
					setcolor(parent(node), BLACK);
					setcolor(right(brother), BLACK);
					leftrotate(parent(node));
					break;
				}
			}
			else
			{
				Node* brother = left(parent(node));
				if (color(brother) == RED)
				{
					setcolor(parent(node), RED);
					setcolor(brother, BLACK);
					rightrotate(parent(node));
					brother = left(parent(node));
				}
				if (color(brother->left_) == BLACK && color(brother->right_) == BLACK)
				{
					setcolor(brother, RED);
					node = parent(node);
				}
				else
				{
					if (color(brother->left_) != RED)
					{
						setcolor(brother, RED);
						setcolor(brother->left_, BLACK);
						lefttrotate(brother);
						brother = parent(node)->left_;
					}
					setcolor(brother, color(parent(node)));
					setcolor(parent(node), BLACK);
					setcolor(left(brother), BLACK);
					rightrotate(parent(node));
					break;
				}
			}
		}
		setcolor(node, BLACK);
	}
	Node* root_;
};

