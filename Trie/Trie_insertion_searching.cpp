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

    struct trienode * root;

    void insert_str(string &s, int n)
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

    bool search_str(string s, int n)
    {
        trienode * curr = root;
        int i = 0;
        while (i < n)
        {
            if(curr -> child[s[i] - 'a'] != NULL)
            {
                curr = curr -> child[s[i] - 'a'];
            }
            else
            {
                return false;
            }
        }

        if( curr -> isEnd == true)
        return true;
        return false;
        
    }

    int main()
    {
        string s1 = "yash";
        insert_str(s1, 4);
    }
