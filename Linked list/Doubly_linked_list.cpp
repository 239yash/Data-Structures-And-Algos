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

node* insertend(node*head, int key)
{
    node * temp = new node(key);
    if(head == NULL)
    {
        return temp;
    }
    else
    {
        node * curr = head;
        // Reaching to node of the given value.
        while(curr -> next != NULL)
        {
            curr = curr -> next;
        }
        curr -> next = temp;
        temp -> next = NULL;
        temp -> prev = curr;
        return head;
    }
    
}

node* insert_before_node(node * head, int key, int value)
{
    node * temp = new node(key);
    node * curr = head;

    // Reaching to node of the given value.
    while(curr -> next -> key != value)
    {
        
        if(curr -> next == NULL)
        {
            cout<<"FALSE"<<endl;    
            return head;    
        }
        curr = curr -> next;
    }

    temp -> prev = curr;
    temp -> next = curr -> next;
    curr -> next -> prev = temp;
    curr -> next = temp;
    

    return head;
}


node* insert_after_node(node* head, int key, int value)
{
    node * temp = new node(key);
    node * curr = head;
    // Reaching to node of the given value.
    while(curr -> key != value)
    {
        // If the node with given value is not found.
        if(curr -> next == NULL)
        {
            cout<<"FALSE";
            return head;
        }
        curr = curr -> next;
    }
    

    // If the node with given value is the last node.
    if(curr -> next == NULL)
    {
        curr -> next = temp;
        temp -> next = NULL;
        temp -> prev = curr;
        return head;
    }

    // If the node with value is the normal node in between of linked list.
    temp -> prev = curr;
    temp -> next = curr -> next;
    curr -> next -> prev = temp;
    curr -> next = temp;
    

    return head;


}


node* delete_node(node* head, int value)
{
    node * curr = head;
    // Reaching to node of the given value.
    while(curr -> key != value)
    {
        // If the node to be deleted not found.
        if(curr -> next == NULL)
        {
            cout<<"THE NODE TO BE DELETED NOE FOUND";
            return head;
        }
        curr = curr -> next;
    }

    // If the node to be deleted is the last node.
    if(curr -> next == NULL)
    {
        curr -> prev -> next = NULL;
        return head;
    }

    // If the node to be deleted is a normal node in between of the list.
    node * s_next = curr -> next;
    node * s_prev = curr -> prev;
    s_next -> prev = s_prev;
    s_prev -> next = s_next;
    free(curr);

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
    head = insert_before_node(head,35,30);
    head = insert_after_node(head,25,30);
    head = delete_node(head,50);
    head = delete_node(head,25);


    printlist(head);

}
