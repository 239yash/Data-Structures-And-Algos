#include <bits/stdc++.h> 
using namespace std; 

struct trienode {
    struct trienode * child[26];
    bool isEnd;

    trienode()
    {
        isEnd = false;
        for(int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

class trie
{
public:
    trie()
    {
        root = new trienode();
    }
    void insert_str(string &s, int n);
    bool search_str(string &s, int n);
private:
    trienode* root;
};



void trie::insert_str(string &s, int n)
{
    trienode * curr = root;
    int i;
    for(i = 0; i < n; i++)
    {
        int index = s[i] - 'a';
        if(curr -> child[index] == NULL)
        {
            curr -> child[index] = new trienode();
        }
        else
        {
            curr = curr -> child[index];
        }
    }

    curr -> isEnd = true;
}

bool trie::search_str(string &s, int n)
{
    trienode * curr = root;
    for(int i = 0; i < n; i++)
    {
        int index = s[i] - 'a';
        if(curr -> child[index] != NULL)
        {
            curr = curr -> child[index];
        }
        else
        {
            return false;
        }
    }

    if( curr -> isEnd == true)
    return true;
    else
    {
        return false;
    }

}

int main()
{
    trie t;
    string s1 = "yash";
    t.insert_str(s1, 4);
    cout<<t.search_str(s1,4);
}


