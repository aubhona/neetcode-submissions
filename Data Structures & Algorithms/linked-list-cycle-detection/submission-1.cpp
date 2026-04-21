/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */
 
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

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if (head == nullptr)
        {
            return false;
        }

        fast = head->next;

        while (slow != fast) {
            if (fast == nullptr)
            {
                return false;
            }

            slow = slow->next;
            fast = fast->next;

            if (fast == nullptr)
            {
                return false;
            }

            fast = fast->next;
        }

        return true;
    }
};
