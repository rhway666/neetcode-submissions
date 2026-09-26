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
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;
        // while繼續的條件是 curr1 還有 或curr2還有 或是carry不是0
        while (curr1 || curr2 || carry) {
            int sum = carry;
            sum += curr1 ? curr1->val : 0;
            sum += curr2 ? curr2->val : 0;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;

            if (curr1) curr1 = curr1->next;
            if (curr2) curr2 = curr2->next;
            
        }
        tail->next = nullptr;
        return dummy.next;
    }
};
/*
ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;
        while (curr1 && curr2) {
            int sum = 0;
            sum = curr2->val + curr1->val + carry;
            carry = sum / 10;
            curr1->val = sum % 10;
            tail->next = curr1;
            tail = tail->next;

            curr1 = curr1->next;
            curr2 = curr2->next;
            if (curr1) {
                curr1->val += carry;
            } else if (curr2) {
                curr2->val += carry;
            } else {
                // both nullptr
                if (carry) {
                    tail->next = new ListNode*(carry);
                } 
                return dummy.next;
            }
            
        }
        if (curr1) {
            while(!curr1 || !carry) {
                int sum = 0;
                sum = curr1->val + carry;
                carry = sum / 10;
                curr1->val = sum % 10;
                tail->next = curr1;
                tail = tail->next; 
            }
            if (carry) {
                tail->next = new ListNode(carry);
            }
        }
        if (curr2) {
            while(!curr2 || !carry) {
                int sum = 0;
                sum = curr2->val + carry;
                carry = sum / 10;
                curr2->val = sum % 10;
                tail->next = curr2;
                tail = tail->next; 
            }
            if (carry) {
                tail->next = new ListNode(carry);
            }
        }
        return dummy.next;
*/
