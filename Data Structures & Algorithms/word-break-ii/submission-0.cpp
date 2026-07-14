class Solution {

private:
    struct TrieNode {
        TrieNode* children[26];
        bool isWord;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isWord = false;
        }
    };

    vector<string> ans;
    TrieNode* trie;

    void backtrack(string s, int i, TrieNode* node, string sentence) {
        if (i == s.length()) {
            if (node->isWord) ans.push_back(sentence);
            return;
        }

        if (node->isWord) {
            backtrack(s, i, trie, sentence + " ");
        };

        char c = s[i];
        int idx = c - 'a';
        if (!node->children[idx]) return;

        node = node->children[idx];
        backtrack(s, i + 1, node, sentence + c);
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        trie = new TrieNode();
        for (string word : wordDict) {
            TrieNode* curr = trie;
            for (char c : word) {
                int idx = c - 'a';
                if (!curr->children[idx]) {
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
            }
            curr->isWord = true;
        }

        backtrack(s, 0, trie, "");
        return ans;
    }
};