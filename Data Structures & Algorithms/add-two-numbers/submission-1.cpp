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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        auto head1 = l1;
        auto head2 = l2;

        if (!l1)
        {
            return l2;
        }

        if (!l2)
        {
            return l1;
        }

        while (l1 || l2) {
            l1->val += l2->val + carry;
        
            carry = l1->val / 10;

            l1->val %= 10;
            l2->val = l1->val;

            if (!l2->next)
            {
                addCarry(l1, carry);
                return head1;
            }

            if (!l1->next)
            {
                addCarry(l2, carry);
                return head2;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        return head1;
    }

    void addCarry(ListNode* l, int carry) {
        if (!carry)
        {
            return;
        }
        
        if (l->next)
        {
            l->next->val += carry;
            carry = l->next->val / 10;
            l->next->val %= 10;
            return addCarry(l->next, carry);
        }

        l->next = new ListNode(carry);
    }
};
