# include<bits/stdc++.h>
using namespace std;

void printlist(int *);
struct node{
    int key;
    node * next;
    node(int x)
    {
        key = x;
        next = NULL;
    }
};

node* insertbegin(node* head, int key)
{
    node* temp = new node(key);
    temp -> next = head;
    return temp;
}


void printlist(node * head)
{
    node* curr = head;
    while(curr != NULL)
    {
        cout<<curr -> key<<endl;
        curr = curr->next;
    }
}


node * sorted_list(node * head1, node * head2)
{
    node * a = head1;
    node * b = head2;
    node * head;
    node * tail;

    if(a == NULL)
    return(b);
    
    if(b == NULL)
    return(a);

    if(a -> key < b -> key )
    { 
        head = a;
        tail = a;
        a = a-> next;
    }
    else
    {
        head = b;
        tail = b;
        b = b -> next;
    }
    
    while( a != NULL && b != NULL )
    {
        if( a -> key < b -> key)
        {
            tail -> next = a;
            tail = tail -> next;
            a = a -> next;
        }
        else
        {
            tail -> next = b;
            tail = tail -> next;
            b = b -> next;
        } 
    }

    if( a == NULL)
    tail -> next = b;

    if( b == NULL)
    tail -> next = a;

    return head;
}

int main()
{
    node * head1 = NULL;
    node * head2 = NULL;
    node * head;
    head1 = insertbegin(head1,40);
    head1 = insertbegin(head1,30);
    head1 = insertbegin(head1,20);
    head1 = insertbegin(head1,10);

    head2 = insertbegin(head2,35);
    head2 = insertbegin(head2,25);
    head2 = insertbegin(head2,15);
    head2 = insertbegin(head2,5);

    head = sorted_list(head1,head2);
    printlist(head);



}
