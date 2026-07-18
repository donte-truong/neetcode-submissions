class WordDictionary {
    struct TrieNode {
        vector<TrieNode*> children;
        bool isWord;

        TrieNode() {
            children.resize(26);
            for (int i = 0; i < children.size(); ++i) {
                children[i] = nullptr;
            }
            isWord = false;
        }
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(string word, int i, TrieNode* curr) {
        for (int j = i; j < word.length(); ++j) {
            if (word[j] == '.') {
                for (TrieNode* child : curr->children) {
                    if (child && dfs(word, j + 1, child))
                        return true;
                }
                return false;
            }

            int idx = word[j] - 'a';
            if (!curr->children[idx]) {
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isWord;
    }
};
