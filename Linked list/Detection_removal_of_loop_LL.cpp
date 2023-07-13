# include<bits/stdc++.h>
using namespace std;
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


node * loop_check(node * head)
{
    node * slow = head;
    node * fast = head;

    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
        {
            cout<<"True !! Loop Found.";
            return slow;
        }
    }
    cout<<"False !! No loop";
    return NULL;
}

node * loop_remove(node * head, node * slow)
{
    node * fast = slow;
    slow = head;
    while(slow != fast)
    {
        slow = slow -> next;
        fast = fast -> next;
    }

    while(slow -> next != fast)
    {
        slow = slow -> next;
    }

    slow -> next = NULL;
    return head;
}


int main()
{
    node * head = NULL;
    head = insertbegin(head,10);
    head = insertbegin(head,20);
    head = insertbegin(head,30);
    head = insertbegin(head,40);
    head = insertbegin(head,50);
    node * check = loop_check(head);
    if(check)
    {
        head = loop_remove(head,check);
    }


}
