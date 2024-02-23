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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* temp = nullptr;
        for (int i = 0; i < lists.size(); i++)
            temp = mergeLists(temp, lists[i]);
        return temp;
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1 -> val < l2 -> val) {
            l1 -> next = mergeLists(l1 -> next, l2);
            return l1;
        } else {
            l2 -> next = mergeLists(l1, l2 -> next);
            return l2;
        }
    }
};
