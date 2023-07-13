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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* d1 = new ListNode();
        ListNode* d2 = new ListNode();
        
        ListNode* p1 = d1;
        ListNode* p2 = d2;
        
        while(head != NULL)
        {
            if(head -> val < x)
            {
                p1 -> next = head;
                p1 = p1 -> next;
            }
            else
            {
                p2 -> next = head;
                p2 = p2 -> next;
            }
            
            head = head -> next;
        }
        
        p1 -> next = d2 -> next;
        p2 -> next = NULL;
        return d1 -> next;
    }
};
