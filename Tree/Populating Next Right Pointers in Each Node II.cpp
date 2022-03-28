/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        if(root -> left) {
            if(root -> right) // If root's right exists
                root -> left -> next = root -> right;
            else { // If root's right does not exists
                Node* temp = root -> next; // We'll try to go for rightmost node on same level which have left or right
                while(temp) { // By the process of next -> next -> next
                    if(temp -> left || temp -> right) { // We will stop if left or right exists
                        if(temp -> left)
                            root -> left -> next = temp -> left;
                        else root -> left -> next = temp -> right;
                        break;
                    }
                    temp = temp -> next;
                }
            }
        }
        if(root -> right && root -> next) {
            Node* temp = root -> next;
            while(temp) {
                if(temp -> left || temp -> right) {
                    if(temp-> left)
                        root -> right -> next = temp -> left;
                    else root -> right -> next = temp -> right;
                    break;
                }
                temp = temp -> next;
            }
        }
        
        connect(root -> right); // Call right child first because we have to complete right side first
     // Then only we'll be able to fill the left side of root
        connect(root -> left);
        return root;
    }
};
