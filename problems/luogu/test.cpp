#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	int val;
	node *right, *left, *parent;
	explicit node(int val): val(val), right(nullptr), left(nullptr), parent(nullptr){}
	void link_left(node *n){
		this->left=n;
		n->parent=this;
	}
	void link_right(node *n){
		this->right=n;
		n->parent=this;
	}
};

void in_order_walk(node *n){
	if (n!=nullptr){
		in_order_walk(n->left);
		cout<<n->val<<endl;
		in_order_walk(n->right);
	}
}

node* search(node *n, int k){
	if (n==nullptr||k==n->val) return n;
	if (k<n->val) return search(n->left, k);
	return search(n->right, k);
}

node* min(node *x){
	node *n=x;
	while (n->left!=nullptr) n=n->left;
	return n;
}

node* max(node *x){
	node *n=x;
	while (n->right!=nullptr) n=n->right;
	return n;
}

node* successor(node *x){
	node *n=x;
	if (n->right!=nullptr) return min(n->right);
	node* y=n->parent;
	while (y!=nullptr&&n==y->right){
		n=y;
		y=y->parent;
	}
	return y;
}

node* predecessor(node *x){
	node *n=x;
	if (n->left!=nullptr) return max(n->left);
	node* y=n->parent;
	while (y!=nullptr&&n==y->left){
		n=y;
		y=y->parent;
	}
	return y;
}

void insert(node *t, int val){
	if (t==nullptr) return;
	node *y{nullptr}, *x=t, new_node{val};
	while (x!=nullptr){
		y=x;
		if (val<x->val) x=x->left;
		else x=x->right;
	}
	if (val<y->val) y->link_left(&new_node);
	else y->link_right(&new_node);
}

int main(){
	int d, e, f;
	cin>>d>>e>>f;
	node a{d}, b{e}, c{f};
	a.right=&b;
	a.left=&c;
	successor(&b);
}