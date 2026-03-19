#include <iostream>
#include <functional>
#include<stack>
#include<deque>
#include<vector>
#include"time.h"
#include<cmath>
using namespace std;

template<typename T,typename compare=less<T>>
class bstree
{
	friend void test();
public:
	bstree() :root_(nullptr) {}
	~bstree() {}

	void n_insert(const T& val)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return;
		}
		Node* cur=root_;
		Node* parent=root_;
		while (cur != nullptr)
		{
			if (cur->data_ == val)
			{
				return;
			}
			else if (Compare(cur->data_, val))
			{
				parent = cur;
				cur = cur->right_;
			}
			else
			{
				parent = cur;
				cur = cur->left_;
			}
		}
		if (!Compare(parent->data_, val))
		{
			parent->left_ = new Node(val);
		}
		else
		{
			parent->right_ = new Node(val);
		}
	}
	void insert(const T& val)
	{
		insert(root_, val);
	}

	void n_remove(const T& val)
	{
		if (root_ == nullptr)
		{
			return;
		}
		Node* cur = root_;
		Node* parent = nullptr;
		while (cur != nullptr)
		{
			if (cur->data_ == val)
			{
				break;
			}
			else if (Compare(cur->data_, val))
			{
				parent = cur;
				cur = cur->right_;
			}
			else
			{
				parent = cur;
				cur = cur->left_;
			}
			
		}
		if (cur == nullptr)
		{
			return;
		}
		if (cur->left_ != nullptr && cur->right_ != nullptr)
		{
			parent = cur;
			Node* pre = cur->left_;
			while (pre->right_ != NULL)
			{
				parent = pre;
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
		if (parent == nullptr)                                   
		{
			root_ = child;
			
		}
		else if (parent->left_ == cur)
		{
			parent->left_ = child;
		}
		else
		{
			parent->right_ = child;
		}
		delete cur;
	}
	void remove(const T& val)
	{
		root_=remove(root_, val);
	}

	bool n_find(const T& val)
	{
		if (root_ == nullptr)
		{
			root_ = new Node(val);
			return false;
		}
		Node* cur = root_;
		Node* parent = root_;
		while (cur != nullptr)
		{
			if (cur->data_ == val)
			{
				return true;
			}
			else if (Compare(cur->data_, val))
			{
				parent = cur;
				cur = cur->right_;
			}
			else
			{
				parent = cur;
				cur = cur->left_;
			}
		}
	
			return false;
		
	}
	bool find(const T& val)
	{
		return find(root_, val);
	}

	void preorder()
	{
		cout << "digui qianxu  ";
		preorder(root_);
		cout << endl;
	}
	void n_preorder()
	{
		cout << "feidigui qianxu" << "  ";
		stack<Node*> s;
		if (root_ == NULL)
		{
			return;
		}
		s.push(root_);
		while (!s.empty())
		{
			Node* node = s.top();
			cout << node->data_ << "  ";	
			s.pop();
			if (node->right_ != nullptr)
			{
				s.push(node->right_);
			}
			if (node->left_ != nullptr)
			{
				s.push(node->left_);
			}	
		}
		cout << endl;
	}
	void inorder()
	{
		cout << "digui zhongxu";
		inorder(root_);
		cout << endl;
	}
	void n_inorder()
	{
		cout << "feidigui zhongxu" << "  ";
		stack<Node*> s;
		if (root_ == NULL)
		{
			return;
		}
				
		Node* node = root_;		
			while(node!=NULL)
			{
				s.push(node);
				node = node->left_;
			}

			while (!s.empty())
			{
				Node* top = s.top();
				s.pop();      
				cout << top->data_ << "  ";

				node = top->right_;
				while (node != nullptr)
				{
					s.push(node);
					node = node->left_;
					
				}
			}
			cout << endl;
		}	
	void postorder()
	{
		cout << "digui houxu  ";
		postorder(root_);
		cout << endl;
	}
	void n_postorder()
	{
		cout << "feidigui houxu  ";
		stack<Node*> s1, s2;
		if (root_ == nullptr)
		{
			return;
		}
		s1.push(root_);
		while (!s1.empty())
		{
			Node* cur = s1.top();
			s2.push(cur);
			s1.pop();
			if (cur->left_ != NULL)
			{
				s1.push(cur->left_);
			}
			if (cur->right_ != NULL)
			{
				s1.push(cur->right_);
			}
		}
		while(!s2.empty())
		{
			cout << s2.top()->data_ << "  ";
		s2.pop();
		}
		cout << endl;
	 }
	void levelorder()
	{
		cout << "digui cengxu";
		int h = level();
		for (int i = 0; i < h; i++)
		{
			levelorder(root_, i);
		}
		cout << endl;

	}
	void n_levelorder()
	{
		cout << "feidigui cengxu";
		deque<Node*> d;
		d.push_front(root_);
		while (!d.empty())
		{
			Node* cur = d.front();
			cout << cur->data_ << "  ";
			d.pop_front();
			if (cur->left_ != NULL)
			{
				d.push_back(cur->left_);
			}
			if (cur->right_ != NULL)
			{
				d.push_back(cur->right_);
			}
		}
		cout << endl;
	}

	int level()
	{
		return level(root_);
	}	 
	int number()
	{
		return number(root_);
	}

	void findval(vector<T>& vec, int i, int j)
	{
		findValues(root_, vec, i, j);

	}
	bool isbstree()
	{
		Node* node = NULL;
		return isbstree(root_,node);
	}
	bool ischild(bstree<T, compare>& child)
	{
		if (child.root_ == NULL)
		{
			return true;
		}
		Node* cur = root_;
		while (cur != nullptr)
		{
			if (cur->data_ == child.root_->data_)
			{
				break;
			}
			else if (Compare(cur->data_, child.root_->data_))
			{
				cur = cur->right_;
			}
			else
			{
				cur = cur->left_;
			}
		}
		if (cur == NULL)
		{
			return false;
		}
		return ischild(cur, child.root_);
	}
	void mirror01()//¾µÏñ·´×ª
	{
		mirror01(root_);
	}
	bool mirror02()//¾µÏñ¶Ô³Æ
	{
		if (root_ == NULL)
			return true;
		mirror02(root_->left_, root_->right_);
	}
	void rebulid(int pre[],int i,int j,int in[],int m,int n)
	{
		root_ = rebuli(pre, i, j, in, m, n);
	}
	bool isbalance()
	{
		int l = 0;
		bool flag = true;
		isbalance(root_,l,flag);
		return flag;
	}
private:
	struct Node
	{
		Node(T data = T())
			:data_(data)
			, left_(nullptr)
			, right_(nullptr)
		{
		}
		T data_;
		Node* left_;
		Node* right_;
	};

	void preorder(Node* node)//VLR
	{
		if (node != nullptr)
		{
			cout << node->data_ << "  ";
			preorder(node->left_);
			preorder(node->right_);

		}
		
	}
	void inorder(Node* node)//LVR
	{

		if (node != nullptr)
		{			
			inorder(node->left_);
			cout << node->data_ << "  ";
			inorder(node->right_);

		}
	}
	void postorder(Node* node)//LRV
	{

		if (node != nullptr)
		{
			postorder(node->left_);			
			postorder(node->right_);
			cout << node->data_ << "  ";

		}
	}
	void levelorder(Node* node, int i)
	{
		if (node == NULL)
		{
			return;
		}
		if (i == 0)
		{
			cout << node->data_ << "  ";
			return;
		}
		levelorder(node->left_, i - 1);
		levelorder(node->right_, i - 1);
	}

 	int number(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int left = level(node->left_);
		int right = level(node->right_);
		return left + right + 1; 
	}
	int level(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		int left=level(node->left_);
		int right =level(node->right_);
		return max(left + 1, right + 1);
	}
	void insert(Node* &node, T val)
	{
		if (node == nullptr)
		{
			node = new Node(val);
			return;
		}
		if (node->data_ == val)
		{
			return;
		}
		if (node->data_ > val)
		{
			insert(node->left_, val);
		}
		else if (node->data_ < val)
		{
			insert(node->right_, val);
		}
	}
	bool find(Node*& node, const T& val)
	{
		if (node == nullptr)
		{
			return false;
		}
		if (node->data_ == val)
		{
			return true;
		}
		if (node->data_ > val)
		{
			find(node->left_, val);
		}
		else if (node->data_ < val)
		{
			find(node->right_, val);
		}
	}
	Node* remove(Node*& node, const T& val)
	{
		if (node == nullptr)
		{
			return nullptr;
		}
		if (node->data_ == val)
		{
			if (node->left_ != nullptr && node->right_ != nullptr)
			{
				Node* pre = node->left_;
				while (pre != nullptr)
				{
					pre = pre->right_;
				}
				node->data_ = pre->data_;
				node->left_ = remove(node->left_, pre->data_);
			}
			else
			{
				if (node->left_ != NULL)
				{
					Node* left = node->left_;
					delete node;
					return left;
				}
				else if (node->right_ != NULL)
				{
					Node* right = node->right_;
					delete node;
					return right;
				}
				else
				{
					delete node;
					return nullptr;
				}
			}
		}
		if (Compare(node->data_, val))
		{
			node->right_ = remove(node->right_, val);
		}
		else
		{
			node->left_ = remove(node->left_, val);
		}
		return node;
	}

	void findValues(Node*cur, vector<T> &vec, int i, int j)
	{
		if (cur == NULL)
		{
			return;
		}
		if (cur->data_ > i)
		{
			findValues(cur->left_, vec, i, j);
		}
		if (cur->data_ >= i && cur->data_ <= j)
		{
			cout << cur->data_ <<"  ";
		}
		if (cur->data_ < j)
		{
			findValues(cur->right_, vec, i, j);
		}
		
	}
	bool isbstree(Node* cur,Node *&pre)
	{
		if (cur == NULL)
		{
			return true;
		}
		if (!isbstree(cur->left_, pre))
		{
			return false;
		}
		if (pre != NULL)
		{
			if (Compare(cur->data_, pre->data_))
			{
				return false;
			}			
		}
		pre=cur;
		return isbstree(cur->right_, pre);
	}
	bool ischild(Node* father, Node* child)
	{
		if (father == NULL && child == NULL)
		{
			return true;
		}
		else if (father == NULL)
		{
			return false;
		}
		else if (child == NULL)
		{
			return true;
		};

		if (father->data_ == child->data_)
		{
			ischild(father->right_, child->right_);
			ischild(father->left_, child->left_);
		}
	}
	void mirror01(Node*cur)
	{
		if (cur == nullptr)
		{
			return;
	    }
		Node* node = cur->right_;
		cur->right_ = cur->left_;
		cur->left_ = node;
		mirror01(cur->right_);
		mirror01(cur->left_);
	}
	bool mirror02(Node* left, Node* right)
	{
		if (left == NULL && right == NULL)
			return true;
		else if (left == NULL || right == NULL)
			return false;
		else if (left->data_ != right->data_)
			return false;
		if (left->data_ == right->data_)
			return mirror02(left->left_, right->right_) && mirror02(left->right_, right->left_);
	}
	Node* rebuli(int pre[], int i, int j, int in[], int m, int n)
	{
		if (i > j || m > n)
		{
			return NULL;
		}
		Node* node = new Node(pre[i]);
		for (int k = m; k < n; k++)
		{
			if (pre[i] == in[k])
			{
				node->left_ = rebuli(pre, i + 1, i + (k - m), in, m, k - 1);
				node->right_ = rebuli(pre,i + (k - m)+1,j, in, k+1,n);
				return node;
			}
		}
		return node;
	}
	int isbalance(Node* node,int l,bool &flag)
	{
		if (node == nullptr)
		{
			return l;
		}
		int left=isbalance(node->left_, l + 1, flag);
		if (!flag)
			return l;
		int right=isbalance(node->right_, l + 1, flag);
		if (!flag)
			return l;
		if (abs(left - right) > 1)
			flag = false;

	}
public:
	
	Node* root_;
	compare Compare;
};


