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
        cout<<curr->key<<endl;
        curr = curr->next;
    }
}


node * segregate(node * head)
{
    node * es = NULL;
    node * ee = NULL;
    node * os = NULL;
    node * oe = NULL;
    node * curr = head;

    while(curr != NULL)
    {
        if(curr -> key % 2 == 0)
        {
            if(es == NULL)
            {
                es = curr;
                ee = es;
            }
            else
            {
                ee -> next = curr;
                ee = ee -> next;
            }
            
        }
        else
        {
            if(os == NULL)
            {
                os = curr;
                oe = os;
            }
            else
            {
                oe -> next = curr;
                oe = oe -> next;
            }
        }

        curr = curr -> next;
        
    }

    if( os == NULL || es == NULL)
        return head;
    
    ee -> next = os;
    oe -> next = NULL;
    return es;


}



int main()
{
    node * head = NULL;
    head = insertbegin(head,10);
    head = insertbegin(head,21);
    head = insertbegin(head,30);
    head = insertbegin(head,41);
    head = insertbegin(head,50);
    head = insertbegin(head,61);
    head = insertbegin(head,70);
    head = insertbegin(head,81);
    printlist(head);
cout<<endl;
    head = segregate(head);
    printlist(head);


}
