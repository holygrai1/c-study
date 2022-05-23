#pragma once
#include<opencv2\opencv.hpp>
#include<iostream>
#include<map>
using namespace std;
using namespace cv;
struct ListNode
{
	int key;
	Mat picture;
	ListNode* pre;
	ListNode* next;
	ListNode(int k, Mat& image) {
		key = k;
	 image.copyTo(picture);
		pre = NULL;
		next = NULL;
	}
	//~ListNode(){
	//}
};
typedef map<int, ListNode*> mp_node;
class LRUCache
{
public:
	LRUCache(int size=2);
	~LRUCache();
	void Remove(ListNode* pNode);
	void SetHead(ListNode* pNode);
	void SetSize(int num);
	bool Exist(int key);
	int Size();
	Mat Get(int key);
	int Set(int key, Mat &photo);


private:
	int m_capacity;    //缓存容量
	ListNode* pHead;   //头节点
	ListNode* pTail;   //尾节点
	mp_node  mp;   //mp用来存数据，
};

LRUCache::LRUCache(int size)
{
	m_capacity = size;
	pHead = NULL;
	pTail = NULL;
}

LRUCache::~LRUCache()
{
	mp_node::iterator it = mp.begin();
	for (; it != mp.end();) {
		//delete it->second;
		it->second = NULL;
		mp.erase(it++);
	};
	pHead = NULL;
	pTail = NULL;

}

void LRUCache::Remove(ListNode* pNode) {
	if (pNode->pre != NULL)
	{
		pNode->pre->next = pNode->next;
	}
	else
	{
		pHead = pNode->next;
	}
	if (pNode->next != NULL)
	{
		pNode->next->pre = pNode->pre;
	}
	else
	{
		pTail = pNode->pre;
	}
}

void LRUCache::SetHead(ListNode* pNode) {


	pNode->next = pHead;
	pNode->pre = NULL;

	if (pHead != NULL)
	{
		pHead->pre = pNode;
	}
	pHead = pNode;
	if (pTail == NULL)
	{
		pTail = pHead;
	}
}


int LRUCache::Set(int key, Mat& photo) {
	mp_node::iterator it = mp.find(key);
	if (it != mp.end()) {
		unique_ptr<ListNode> Node (it->second);
		Node->picture = photo;
		Remove(Node.get());
		SetHead(Node.get());
	}
	else {
		//unique_ptr<ListNode> NewNode=make_unique<ListNode>(key,photo);
		ListNode* NewNode = new ListNode(key, photo);
		if (mp.size() >= m_capacity) {
			mp_node::iterator it = mp.find(pTail->key);
			Remove(pTail);
			delete it->second;
			mp.erase(it);
		}
		SetHead(NewNode);
		mp[key] = NewNode;
	}
}

Mat LRUCache::Get(int key) {
	mp_node::iterator it = mp.find(key);
	if (it != mp.end())
	{
		unique_ptr<ListNode> Node(it->second);
		Remove(Node.get());
		SetHead(Node.get());
		return Node->picture;
	}
	else
	{
		return Mat();
	}
}

void LRUCache::SetSize(int num) {
	m_capacity = num;
}

int LRUCache::Size() {
	return m_capacity;
}

bool LRUCache::Exist(int key) {
	mp_node::iterator it = mp.find(key);
	if (it != mp.end()) {
		return true;
	}
	else {
		return false;
	}
}



