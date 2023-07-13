#include <bits/stdc++.h>
using namespace std;

// Function declaration line, just below this comment.
int insertbegin(int, int);
void printlist(int);
int insertend(int, int);
struct node
{
    int key;
    node *next;
    node(int x)
    {
        key = x;
        next = NULL;
    }
};

node *insertbegin(node *head, int key)
{
    node *temp = new node(key);
    temp->next = head;
    return temp;
}

void printlist(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->key << endl;
        curr = curr->next;
    }
}

node *insertend(node *head, int key)
{
    if (head == NULL)
    {
        head = new node(key);
        return head;
    }
    head->next = insertend(head->next, key);
    return head;
}

bool is_pallindrome(node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    else
    {
        std::stack<int> s;
        node *curr = head;
        while (curr != NULL)
        {
            s.push(curr->key);
            curr = curr->next;
        }

        curr = head;

        while (curr != NULL)
        {
            if (curr->key != s.top())
            {
                return 0;
            }
            s.pop();
            curr = curr->next;
        }

        return 1;
    }
}

int main()
{
    node *head = NULL;
    head = insertbegin(head, 10);
    head = insertbegin(head, 20);
    head = insertbegin(head, 20);
    head = insertbegin(head, 20);
    head = insertbegin(head, 10);
    //head = insertend(head,50);
    cout << is_pallindrome(head);
}
