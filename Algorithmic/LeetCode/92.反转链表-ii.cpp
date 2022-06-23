/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *old_head = head;

        ListNode *pre_head = nullptr;
        ListNode *new_head = nullptr;
        int i = 1;
        while (head)
        {
            if (i < left)
            {
                pre_head = head;
                head = head->next;
                i++;
            }
            else if (i >= left && i <= right)
            {
                ListNode *next = head->next;
                head->next = new_head;
                new_head = head;
                head = next;
                i++;
                if (next == nullptr)
                {
                    if (pre_head != nullptr)
                    {
                        pre_head->next->next = head;
                        pre_head->next = new_head;
                    }
                    else
                    {
                        old_head->next = head;
                    }
                    break;
                }
            }
            else
            {
                if (pre_head != nullptr)
                {
                    pre_head->next->next = head;
                    pre_head->next = new_head;
                }
                else
                {
                    old_head->next = head;
                }
                break;
            }
        }
        return pre_head != nullptr ? old_head : new_head;
    }
};
// @lc code=end
