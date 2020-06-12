// root: head node
Node *removeDuplicates(Node *root)
{
    // your code goes here
    if(root == NULL || root -> next == NULL)
    {
        return root;
    }
    Node* slow = root;
    Node* fast = root -> next;
    Node* temp;
    
    while( fast -> next != NULL && fast != NULL)
    {
        if( slow -> data == fast -> data)
        {
            slow -> next = fast -> next ;
            temp = fast ;
            fast = fast -> next;
            delete temp;
        }
        else
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
    
    if(slow -> data == fast -> data && fast != NULL)
    {
        slow -> next = NULL;
        delete fast;
    }
    
    return root;
    
}
