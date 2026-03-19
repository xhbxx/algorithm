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

class doublecirclelink
{
public:
	doublecirclelink()
	{
		head_ = new Node();
		head_->next_ = head_;
		head_->pre_ = head_;
	}
	~doublecirclelink()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			head_->next_ = p->next_;
			p->next_->pre_ = head_;
			delete p;
			p=head_->next_;
		}
		delete head_;
		head_ = nullptr;
	}
	void push_front(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		node->pre_ = head_;
		head_->next_->pre_ = node;
		head_->next_ = node;
	}
	void push_back(int val)
	{
		Node* node = new Node(val);
		head_->pre_->next_ = node;
		node->pre_ = head_->pre_;
		head_->pre_ = node;
		node->next_ = head_;
	}
	void remove(int val) 
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			if (p->data_ == val)
			{
				p->pre_->next_ = p->next_;
				p->next_->pre_ = p->pre_;
				delete p;
				return;
			}
			p = p->next_;
		}
	}
	bool find(int val)
	{
		Node* p = head_->next_;
		while (p != head_)
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
		while (p != head_)
		{
			cout << p->data_ << "  ";
			p = p->next_;
		}
		cout << endl;
	}
private:
	Node *head_;

};
	int main()
	{
		doublecirclelink f;
		f.push_front(2);
		f.push_back(1);
		f.push_front(3);
		f.remove(1);
		if (!f.find(3))
		{
			cout << "no";
		}
		f.show();
	}
