/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (46.77%)
 * Likes:    183
 * Dislikes: 0
 * Total Accepted:    37.5K
 * Total Submissions: 79.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ptr1 = head;
        while(nullptr != ptr1){
            ListNode *ptr2 = ptr1;
            while(nullptr != ptr2){
                if(nullptr == ptr2->next || ptr2->val != ptr2->next->val){
                    ptr1->next = ptr2->next;
                    break;
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }//end for while
            ptr1 = ptr1->next;
        }//end for while
        return head;
    }
};

