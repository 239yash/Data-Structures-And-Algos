# include<bits/stdc++.h>
using namespace std;

// Function declaration line, just below this comment.
int insertbegin(int,int);
void printlist(int);
int insertend(int,int);
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

node* insertend(node*head, int key)
{
    if(head == NULL)
    {
        head = new node(key);
        return head;
    }
    head -> next = insertend(head->next,key);
    return head;
}   

int main()
{
    node* head = NULL;
    head = insertbegin(head,10);
    head = insertbegin(head,20);
    head = insertbegin(head,30);
    head = insertbegin(head,40);
    head = insertend(head,50);
    printlist(head);

}
