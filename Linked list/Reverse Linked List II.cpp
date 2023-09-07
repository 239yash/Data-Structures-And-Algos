class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL)
            return NULL;
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp1 = head;
        ListNode *leftPrev = dummy;
        
        for(int i=0; i<left-1; i++){
            leftPrev = temp1;
            temp1 = temp1->next;
        }
        
        ListNode *prev = NULL;
        for(int i=0; i<right-left+1; i++){
            ListNode* nextNode = temp1->next;
            temp1->next = prev;
            prev = temp1;
            temp1 = nextNode;
        }
        
        leftPrev->next->next = temp1;
        leftPrev->next = prev;
        
        return dummy->next;
    }
};








// Given the head of a singly linked list and two integers left and right where left <= right, 
// reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
