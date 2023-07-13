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


void loop_check(node * head)
{
    node * temp = new node(0);
    node * curr = head;
    node * store;
    while(curr -> next != NULL)
    {
        if(curr -> next == temp)
        {
            cout<<"True";
            return;
        }

        store = curr -> next;
        curr -> next = temp;
        curr = store;
    }
    cout<<"False";
    return;

}



int main()
{
    node * head = NULL;
    head = insertbegin(head,10);
    head = insertbegin(head,20);
    head = insertbegin(head,30);
    head = insertbegin(head,40);
    head = insertbegin(head,50);
    loop_check(head);


}
