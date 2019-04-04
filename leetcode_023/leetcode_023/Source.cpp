#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) return nullptr;
		ListNode *l0 = new ListNode(0);
		ListNode *head = l0;
		ListNode *l1 = l0;
		int flag;
		for (int k = 0; k < lists.size(); ++k) {
			if (lists[k] == nullptr) {
				lists.erase(lists.begin() + k);
				--k;
			}
		}
		while (lists.size() != 0) {
			for (int i = 0; i < lists.size(); ++i) {
				if (i == 0) {
					l1 = lists[0];
					flag = 0;
				}
				else {
					if (lists[i]->val < l1->val) {
						l1 = lists[i];
						flag = i;
					}
				}
			}
			l0->next = lists[flag];
			l0 = l0->next;
			if (lists[flag]->next != nullptr)
				lists[flag] = lists[flag]->next;
			else
				lists.erase(lists.begin() + flag);
		}
		return head->next;
	}
};