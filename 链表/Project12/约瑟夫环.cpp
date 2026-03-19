#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;
struct	Node
{
	Node(int data = 0) :data_(data), next_(nullptr) {}
	int data_;
	Node* next_;
};
void joseph(Node* head, int k, int m)
{
	Node* p = head;
	Node* q = head;
	while (q->next_ != head)
	{
		q = q->next_;
	}
	for (int i = 1; i < k; i++)
	{
		q = q->next_;
		p = p->next_;
	}
	for(;;)
	{
		for (int i = 1; i < m; i++)
		{
			p = p->next_;
			q = q->next_;
		}
		cout << p->data_ << "  ";
		if (p == q)
		{
			delete p;
			break;
		}
		q->next_ = p->next_;		
		delete p;
		p = q->next_;
	}
}
	

