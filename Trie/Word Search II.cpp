class TrieNode {
    public:
        TrieNode* children[26];
        bool flag;
        TrieNode() {
            flag = false;
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }
};



class Solution {
public:
    TrieNode* root;
    unordered_set<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        insertWords(words);
        searchWords(board);
        std::vector<string> res;
        for (auto x : ans)
            res.push_back(x);
        return res;
    }
    
    void searchWords(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        string temp = "";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(i, j, temp, board);
            }
        }
    }
    
    void search(int i, int j, string& temp, vector<vector<char>>& board) {
        if (i < 0 
            || j < 0 
            || i >= board.size() 
            || j >= board[0].size() 
            || board[i][j] == '.') 
            return;
        
        char ch = board[i][j];
        temp.push_back(ch);
        
        TrieNode* checkPrefix = startsWith(temp);
        if (checkPrefix == NULL) {
            temp.pop_back();
            return;
        }
        if (checkPrefix -> flag){
            ans.insert(temp);
        }
        
        board[i][j] = '.';
        search(i + 1, j, temp, board);
        search(i, j + 1, temp, board);
        search(i - 1, j, temp, board);
        search(i, j - 1, temp, board);
        board[i][j] = ch;
        temp.pop_back();
    }
    
    void insertWords(vector<string>& words) {
        for (auto x : words) {
            insertWord(x);
        }
    }
    
    void insertWord(string word) {
        TrieNode* node = root;
        for (auto x : word) {
            if (node -> children[x - 'a'] == NULL) {
                node -> children[x - 'a'] = new TrieNode();
            }
            node = node -> children[x - 'a'];
        }
        node -> flag = true;
    }
    
    TrieNode* startsWith(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (node -> children[c - 'a'] == NULL)
                return NULL;
            node = node -> children[c - 'a'];
        }   
        return node;
    }
};






// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
// The same letter cell may not be used more than once in a word.

// Example 1:


// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:


// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []
 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.
