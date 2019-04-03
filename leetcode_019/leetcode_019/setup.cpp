#include<iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int a, ListNode *b):val(a), next(b){}
	//ListNode(){}
};


class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		int *p = new int(-5);
		int *flag = new int(0);
		if (!head->next) return nullptr;
		func(head, p, n, flag);
		if (!*flag) head = head->next;
		return head;
	}

	void func(ListNode *L, int *p, int n, int *flag) {
		if (!L->next) {
			*p = 2;
			return;
		}
		func(L->next, p, n, flag);
		if (*p == n + 1) {
			ListNode *tmp = L->next;
			if (!tmp->next)
				L->next = nullptr;
			else
				L->next = tmp->next;
			*flag = 1;
		}
		++*p;
		return;
	}
};