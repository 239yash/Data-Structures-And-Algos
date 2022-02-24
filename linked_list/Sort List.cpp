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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        fast = slow -> next;
        slow -> next = NULL;
        return merge(sortList(head), sortList(fast));
    }
    
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* curr = new ListNode(0);
        ListNode* ans = curr;
        while(a != NULL && b != NULL) {
            if (a -> val < b -> val) {
                curr -> next = a;
                a = a -> next;
            } else {
                curr -> next = b;
                b = b -> next;
            }  
            curr = curr -> next;
        }
        
        if(a != NULL) curr -> next = a;
        else curr -> next = b;
        return ans -> next;
    }
};
