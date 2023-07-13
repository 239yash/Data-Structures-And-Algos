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


node * swap_pairs(node * head)
{
    if( head == NULL || head -> next == NULL)
    return head;

    node * prev = head;
    node * curr = head -> next -> next;
    node * store;

    head = head -> next;
    head -> next = prev;

    while ( curr != NULL && curr -> next != NULL)
    {
        prev -> next = curr -> next;
        prev = curr;
        store = curr -> next -> next;
        curr -> next -> next = curr;
        curr = store;
    }
    prev -> next = curr;
    return head;
}


int main()
{
    node * head = NULL;
    head = insertbegin(head,10);
    head = insertbegin(head,21);
    head = insertbegin(head,22);
    head = insertbegin(head,23);
    head = insertbegin(head,24);
    head = insertbegin(head,25);
    head = insertbegin(head,26);


    printlist(head);
    cout<<endl;
    head = swap_pairs(head);
    printlist(head);



}
