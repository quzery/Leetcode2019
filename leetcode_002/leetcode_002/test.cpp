#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *p1(l1), *p2(l2);
		ListNode *header = new ListNode(0);
		ListNode *curr = header;
		int carry = 0;
		while (p1 || p2) {
			int x = p1 ? p1->val : 0;
			int y = p2 ? p2->val : 0;
			int sum = x + y + carry;
			if (sum > 9) {
				sum %= 10;
				carry = 1;
			}
			else carry = 0;
			curr->next = new ListNode(sum);
			curr = curr->next;
			if (p1->next) p1 = p1->next; else p1 = nullptr;
			if (p2->next) p2 = p2->next; else p2 = nullptr;
		}

		if (carry > 0) curr->next = new ListNode(carry);

		return header->next;
	}
};