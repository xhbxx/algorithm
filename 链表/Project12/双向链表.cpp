#include<iostream>
using namespace std;
struct Node
{
	Node(int data = 0)
		:data_(data)
		, next_(nullptr)
		, pre_(nullptr)
	{
	}
	int data_;
	Node* next_;
	Node* pre_;
};

class doublelink
{
public:
	doublelink()
	{
		head_ = new Node();
	}
	~doublelink()
	{
		Node* p = head_;
		while (p != nullptr)
		{
			p = p->next_;
			delete head_;
			head_ = p;
		}

	}
public:
	void push_back(int val)
	{
		Node* p = head_;
		while (p->next_ != nullptr)
		{
			p = p->next_;
		}
		Node* node = new Node(val);
		p->next_ = node;
		node->pre_ = p;
	}
	void push_front(int val)
	{
		
		Node* node = new Node(val);
		node->next_ = head_->next_; 
		node->pre_ = head_;
		if(head_->next_!=nullptr)
		{
			head_->next_->pre_= node;
		}
		head_->next_ = node;
	}
	void remove(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				p->pre_->next_ = p->next_;
				if (p->next_ != nullptr)
				{
					p->next_->pre_ = p->pre_;
				}												
				delete p;
				return;
			}
			p = p->next_;
		}
		cout << "no haev" << endl;
	}
	bool find(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				return true;
			}
			p = p->next_;
		}
		return false;
	}
	void show()
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			cout << p->data_ << "  ";
			p = p->next_;
		}
		cout << endl;
	}
private:
	Node* head_;
};

