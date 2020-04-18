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


void print_nEnd(node * head, int n)
{
    node * first = head;
    node * second = head;

    for(int i = 1; i < n; i++)
    {
        first = first -> next;
    }

    while(first -> next != NULL)
    {
        second = second -> next;
        first = first -> next;
    }

    cout<<"THE Nth NODE FROM END IS - "<<second -> key;
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
    head = insertbegin(head,50);
    print_nEnd(head,2);
    //printlist(head);

}
