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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Two pass approach:
        //    - first pass find length N
        //    - second pass remove (N-n)th node from the front
        // then return head

        int length = 0;
        ListNode* cur = head;
        while (cur) {
            length++;
            cur = cur->next;
        }

        if (length - n == 0) return head->next;

        cur = head;

        for (int i = 0; i < length - n - 1; i++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;

        return head;
    }
};
