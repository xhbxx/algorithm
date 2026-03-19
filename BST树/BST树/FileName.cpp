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