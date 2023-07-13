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


void print_mid(node * head)
{
    node* slow = head;
    node* fast = head;

    for(slow = head; slow -> next != NULL; slow = slow -> next)
    {
        if(slow == NULL)
        {
            cout<<"No node present";
            return;
        }

        if(fast -> next == NULL)
        {
            cout<<slow->key<<endl;
            return;
        }

        fast = fast -> next;
        //slow = slow -> next;

        if(fast -> next == NULL)
        {
            cout<<slow->key<<endl;
            return;
        }

        fast = fast -> next;

    }
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

int main()
{
    node * head = NULL;
    head = insertbegin(head,10);
    head = insertbegin(head,20);
    head = insertbegin(head,30);
    head = insertbegin(head,40);
    printlist(head);
    print_mid(head);
}
