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


class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
		for (int i = 0; i < word.size(); i++) {
			if (node -> children[word[i] - 'a'] == NULL) {
				node -> children[word[i] - 'a'] = new TrieNode();
			}
			node = node -> children[word[i] - 'a'];
		}
        node -> flag = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (node -> children[c - 'a'] == NULL)
                return false;
            node = node -> children[c - 'a'];
        }
        return node -> flag;
    }
    
    bool startsWith(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (node -> children[c - 'a'] == NULL)
                return false;
            node = node -> children[c - 'a'];
        }   
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
