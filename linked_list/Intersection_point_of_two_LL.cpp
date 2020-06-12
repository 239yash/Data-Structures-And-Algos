int intersectPoint(Node* head1, Node* head2){
    Node* curr = head1;
    Node* temp = head1 -> next;
    Node* naya = new Node(-99);
    while(temp != NULL)
    {
        curr -> next = naya;
        curr = temp;
        temp = temp -> next;
    }
    
    curr -> next = naya;
    curr = head2;
    
    while(curr -> next != NULL)
    {
        if(curr -> next == naya)
        {
            return curr-> data;
        }
        curr = curr -> next;
    }
    
    return -1;
    
    
}
