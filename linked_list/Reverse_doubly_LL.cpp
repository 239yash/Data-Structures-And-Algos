# include<bits/stdc++.h>
using namespace std;

// Function declaration line, just below this comment.
int insertbegin(int,int);
void printlist(int);
int insertend(int,int);
struct node{
    int key;
    node * next;
    node * prev;
    node(int x)
    {
        key = x;
        next = NULL;
        prev = NULL;
    }
};

node* insertbegin(node* head, int key)
{
    node* temp = new node(key);
    temp -> next = head;
    temp -> prev = NULL;
    if(head != NULL)
    head -> prev = temp;
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

node * reverse_ll(node * head)
{
    node * temp = head;
    while(temp != NULL)
    {
        swap(temp ->next, temp -> prev);

        if(temp -> prev == NULL)
        {
            return temp;
        }
        temp = temp -> prev;
    }
}










int main()
{
    node* head = NULL;
    head = insertbegin(head,10);
    head = insertbegin(head,20);
    head = insertbegin(head,30);
    head = insertbegin(head,40);
    head = insertbegin(head,50);
    head = insertbegin(head,60);
    printlist(head);
    cout<<endl;
    head = reverse_ll(head);
    printlist(head);






}
