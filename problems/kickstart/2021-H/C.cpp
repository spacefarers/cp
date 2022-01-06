//
// Created by spacefarers on 10:24 PM Nov 13 2021.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <queue>

#define f first
#define s second
#define ll long long

using namespace std;

struct LinkedNode{
	int val{};
	LinkedNode*linkTo=nullptr,*parent=nullptr;
	explicit LinkedNode(int val):val(val){}
};

priority_queue<pair<int,LinkedNode*>,vector<pair<int,LinkedNode*>>,greater<>> q,q1;

void checkNode(LinkedNode*node,int x=10){
	auto*frontNode=node->parent;
	auto*backNode=node->linkTo;
	if (frontNode!=nullptr&&(frontNode->val+1)%10==node->val){
		if (frontNode->val<=x){
			q.push({frontNode->val,frontNode});
		} else {
			q1.push({frontNode->val,frontNode});
		}
	}
	if (backNode!=nullptr&&(node->val+1)%10==backNode->val){
		if (node->val<=x){
			q.push({node->val,node});
		} else {
			q1.push({node->val,node});
		}
	}
}

int main(){
	int T;
	cin>>T;
	for (int i=1;i<=T;i++){
		set<LinkedNode*> removed;
		int x;
		string a;
		cin>>x>>a;
		auto*root=new LinkedNode(a[0]-'0');
		auto*prevNode=root;
		for (int j=1;j<x;j++){
			auto*newNode=new LinkedNode(a[j]-'0');
			prevNode->linkTo=newNode;
			newNode->parent=prevNode;
			prevNode=newNode;
			checkNode(newNode);
		}
		auto*validNode=root;
		while (true){
			swap(q,q1);
			while (!q1.empty()){
				auto u=q1.top();
				q1.pop();
				if (removed.find(u.s)!=removed.end()||u.s->linkTo==nullptr||(u.s->val+1)%10!=u.s->linkTo->val) continue;
				removed.insert(u.s);
				removed.insert(u.s->linkTo);
				auto*newNode=new LinkedNode((u.f+2)%10);
				auto frontConNode=u.s->parent;
				auto backConNode=u.s->linkTo->linkTo;
				if (frontConNode!=nullptr)
					frontConNode->linkTo=newNode;
				newNode->parent=frontConNode;
				if (backConNode!=nullptr)
					backConNode->parent=newNode;
				newNode->linkTo=backConNode;
//				u.s->linkTo->linkTo=nullptr;
//				u.s->linkTo->parent=nullptr;
//				u.s->linkTo=nullptr;
//				u.s->parent=nullptr;
				validNode=newNode;
				checkNode(newNode,u.first);
			}
			if (q.empty()) break;
		}
		while (validNode->parent!=nullptr) validNode=validNode->parent;
		string ans;
		while (validNode!=nullptr){
			ans+=to_string(validNode->val);
			validNode=validNode->linkTo;
			removed.insert(validNode);
		}
		for (auto&j:removed){
			delete j;
		}
		cout<<"Case #"<<i<<": "<<ans<<endl;
	}
}

