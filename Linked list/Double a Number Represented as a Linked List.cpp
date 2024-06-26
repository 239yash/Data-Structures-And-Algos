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
    ListNode* doubleIt(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* curr = head = reverseList(head);
                
        int extra = 0;
        while(curr != nullptr) {
            int dbl = curr -> val * 2;
            if (dbl >= 10) {
                curr -> val = (dbl % 10) + extra;
                extra = 1;
            } else {
                curr -> val = dbl + extra;
                extra = 0;
            }
            curr = curr -> next;
        }
        
        if (extra) {
            ListNode* temp = head;
            while(temp -> next != nullptr)
                temp = temp -> next;
            temp -> next = new ListNode(1);
        }
        
        return reverseList(head);
    }
    
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head -> next == NULL) return head;
        ListNode* prev = NULL;

        while(head) {
            ListNode* temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};









// You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

// Return the head of the linked list after doubling it.

 

// Example 1:


// Input: head = [1,8,9]
// Output: [3,7,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
// Example 2:


// Input: head = [9,9,9]
// Output: [1,9,9,8]
// Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998. 
 

// Constraints:

// The number of nodes in the list is in the range [1, 104]
// 0 <= Node.val <= 9
// The input is generated such that the list represents a number that does not have leading zeros, except the number 0 itself.
