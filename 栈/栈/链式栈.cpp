#include<iostream>
using namespace std;
class linkstack{
public:
	linkstack() { head_ = new Node; }
	~linkstack()
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			head_ = head_->next_;			
			delete p;
			p = head_;
		}
	}
public:
	void push(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		head_->next_ = node;
		size_++;
	};
	void pop()
	{
		if (head_->next_ == nullptr)
			throw "stack is empty";
		Node* p = head_->next_;
		head_->next_ = p->next_;
		delete p;
	}
	int top() const
	{if(head_->next_==nullptr)
		throw "is empty";
		return head_->next_->data_;
	}
	bool empty()
	{
		return head_->next_ == nullptr;
	}
	int size() const
	{
		
		return size_;
	}
	
private:
	struct Node
	{
		Node(int data = 0) :
			data_(data)
			, next_(nullptr) {}
		Node* next_;
		int data_;
	};
	int size_;
	Node* head_;
};
