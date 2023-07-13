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



node* reverse_ll(node * head)
{
    node * curr = head;
    node * curr1 = head -> next;
    node * temp;
    

    while(curr1  != NULL)
    {
        temp = curr1 -> next;
        curr1 -> next = curr;
        curr = curr1;
        curr1 = temp;
    }
    head -> next = NULL;
    return curr;
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
    printlist(head);
    cout<<endl;
    head = reverse_ll(head);
    printlist(head);

}
