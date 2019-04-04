#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int a):val(a), next(nullptr){}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode * l0 = new ListNode(0);
		ListNode * head = l0;
		while (!(l1 == nullptr || l2 == nullptr)) {
			if (l1->val < l2->val) {
				l0->next = l1;
				l0 = l0->next;
				l1 = l1->next;
			}
			else{
				l0->next = l2;
				l0 = l0->next;
				l2 = l2->next;
			}
		}
		if (l1 == nullptr) l0->next = l2;
		else l0->next = l1;
		return head->next;
	}
};