Node * removeDuplicates( Node *head) 
{
    set<int> s;
    Node *t=head;
    s.insert(t->data);
    while(t->next!=NULL)
    {
        if(s.find(t->next->data)!=s.end())
        {
            t->next=t->next->next;
        }
        else
        {
            t=t->next;
            s.insert(t->data);
        }
    }
    return head;
}
