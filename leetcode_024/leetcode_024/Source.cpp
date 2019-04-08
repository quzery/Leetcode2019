#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int a):val(a), next(nullptr){}
};

class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return head;
		ListNode *p = head, *q = nullptr, *tmp = nullptr;
		q = head->next;
		p->next = q->next;
		q->next = p;
		head = q;
		while (p->next != nullptr && p->next->next !=nullptr) {
			tmp = p;
			p = p->next;
			q = p->next;
			tmp->next = q;
			p->next = q->next;
			q->next = p;
		}
		return head;
	}
};