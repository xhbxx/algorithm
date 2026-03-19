#include<iostream>
using namespace std;
struct	Node
{	Node(int data = 0):data_(data),next_(nullptr){}
	int data_;
	Node* next_;
}; 
class clink
{
public:
	clink()
	{
		head_ = new Node();
	}
	~clink()
	{
		Node* p = head_;
		while (p->next_ != nullptr)
		{
			head_ = head_->next_;
			delete p;
			p = head_;
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
	}
	void push_front(int val)
	{
		
		Node* node = new Node(val);
		node->next_ = head_->next_;
		head_->next_ = node;
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
	bool find(int val)
	{
		Node* p = head_->next_;
		while (p->next_ != nullptr) 
		{
			if (p->data_ == val)
			{
				return true;
			}
			else
			{
				p = p->next_;
			}
	 	}
	}
	void remove(int val)
	{
		Node* p = head_->next_;
		Node* q = head_;
		while (p != nullptr) 
		{
			if (p->data_ == val) 
			{
				q->next_ = p->next_;
				delete p;
				return;
			}
			else
			{
				q = p;
				p = p->next_;
			}

		}
	}
	void removeall(int val)
	{
		Node* p = head_->next_;
		Node* q = head_;
		while (p != nullptr)
		{
			if (p->data_ == val)
			{
				q->next_ = p->next_;
				delete p;
				p = q->next_;
			}	
			else 
			{
				q = p;
				p = p->next_;
			}
		}
	}
	void reverse(clink& link)
	{
		Node*p = link.head_->next_;
		if (p == nullptr) {
			return;
		}
		link.head_->next_ = nullptr;
		while (p != nullptr) 
		{
			Node* q = p->next_;
			p->next_ = link.head_->next_;
			link.head_->next_ = p;
			p = q;
		}	
	}
	bool getlaskknode(clink& link, int k, int& val)
	{
		Node* p = head_;
		Node* q = head_;
		if (k < 1)
		{
			return false;
		}
		for (int i = 0; i < k; i++)
		{
			p = p->next_;
			if (p == nullptr)
			{
				return false;
			}
		}
		while (p != nullptr)
		{
			q = q->next_;
			p = p->next_;
		}
		
		val = q->data_;
		return true;
	}
	void mergelink(clink& l, clink& k)
	{
		Node* p = l.head_->next_;
		Node* q = k.head_->next_;
		Node* last = l.head_;
		while (q != nullptr && p != nullptr)
		{
			if (p->data_ >= q->data_)
			{
				last->next_ = q;
				q = q->next_;
				last = last->next_;
				
			}
			else
			{
				last->next_ = p;
				p = p->next_;
				last = last->next_;
				
			}
		}
		if (p == nullptr)
		{
			last->next_ = q;
		}
		else
		{
			last->next_ = p;
		}
		k.head_->next_ = nullptr;
		
	}
	
public:
	Node* head_;

};
bool islinkhascircle(Node* head, int &val)//不可能被越过
{
	Node* p = head;
	Node* q = head;
	while (p != nullptr&&p->next_ != nullptr)
	{
		q = q->next_;
		p = p->next_->next_;
		
		if (p == q)
		{
			p = head;
			while (p != q)
			{
				q = q->next_;
				p = p->next_;

			}
			val = p->data_;
			return true;
		}
	}
	return false;
}
bool islinkhasmerge(Node*j ,Node*k,int &val)
{
	int i=0;
	int f=0;
	Node* p= j->next_;
	Node* q = k->next_;
	while (p != nullptr)
	{
		i++;
		p = p->next_;
	}
	while (q != nullptr)
	{
		f++;
		q = q->next_;
	}	
	p = j->next_;
	q = k -> next_;
	if (i > f)
	{
		int a = i - f;
		while(a -- >0)
		{
			p = p->next_;
		}
	}
	else 
	{
		int a = f -i;
		while (a-- > 0)
		{
			q = q->next_;
		}
	}
	while (p != nullptr && q != nullptr)
	{
		if (p == q)
		{
			val = p->data_;
			return true;
		}
		p = p->next_;
		q = q->next_;		
	}
	return false;

}
