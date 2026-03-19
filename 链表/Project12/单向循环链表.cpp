#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;
class circlelink
{
public:
	circlelink()
	{
		head_ = new Node();
		tail_ = head_;
		head_->next_ = head_;
	}
	~circlelink()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			head_->next_ = p->next_;
			delete p;
			p = head_->next_;
		}
		delete head_;
	}
public:
	void push_back(int val)
	{
		Node* node = new Node(val);
		node->next_ = tail_->next_;
		tail_->next_ = node;
		tail_ = node;

	}
	void push_front(int val)
	{
		Node* node = new Node(val);
		node->next_=head_->next_;
		head_->next_ = node;
		if (node->next_ == head_)
		{
			tail_ = node;
		}
	}
	void remove(int val)
	{
		Node* p = head_->next_;
		Node* q = head_;
		while (p!= head_)
		{
			if (p->data_ == val)
			{
				q->next_ = p->next_;
				if (p == tail_)
				{
					tail_ = q;
				}
				delete p;
				return;
			}
			p = p->next_;
			q = q->next_;
		}
		cout << "no" << endl;
	}
	bool find(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			p = p->next_;
			if (p->data_ == val)
			{
				return true;
			}
		}
		return false;
	}
	void show()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			cout << p->data_ << "  ";
			p = p->next_;
		}
		cout << endl;
	}
private:
	struct Node
	{
		Node(int data = 0):data_(data),next_(nullptr){}
		int data_;
		Node* next_;
	};
	Node* head_;
	Node* tail_;
};
