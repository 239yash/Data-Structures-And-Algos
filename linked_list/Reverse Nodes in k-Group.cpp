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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        ListNode* preHeader = new ListNode(-1);
        preHeader -> next = head;
        ListNode* curr = preHeader, *prev = preHeader, *nxt, *temp;
        int n = 0;
        while(curr -> next) {
            n++;
            curr = curr -> next;
        } 
        while(n >= k) {
            curr = prev -> next;
            nxt = curr -> next;
            for(int i = 1; i < k; i++) {
                temp = nxt -> next;
                curr -> next = temp;
                nxt -> next = prev -> next;
                prev -> next = nxt;
                nxt = temp;
            }
            prev = curr;
            n -= k;
        }
        return preHeader -> next;
    }
};
