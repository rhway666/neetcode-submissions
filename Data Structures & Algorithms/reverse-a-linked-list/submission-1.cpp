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
    ListNode* reverseList(ListNode* head) {
        // termination
        if (!head || !head->next) return head;

        ListNode* newhead = reverseList(head->next);
        // 1->2->3->null
        //    h. hn 
        // hnn(3的next) 指回2(h)
        head->next->next = head;
        head->next = nullptr;
        return newhead;
    }
};
