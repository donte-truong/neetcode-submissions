class Solution {

private:
    struct TrieNode {
        TrieNode* children[26];
        bool isWord;

        TrieNode() {
            for (int i = 0; i < 26; i++) children[i] = nullptr;
            isWord = false;
        }
    };

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        TrieNode* trie = new TrieNode();

        for (string str : dictionary) {
            TrieNode* curr = trie;
            for (char c : str) {
                int idx = c - 'a';
                if (!curr->children[idx]) {
                    curr->children[idx] = new TrieNode();
                }
                curr = curr->children[idx];
            }
            curr->isWord = true;
        }

        const int n = s.length();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1 + dp[i + 1];

            TrieNode* curr = trie;
            for (int j = i; j < n; j++) {
                char c = s[j];
                int idx = c - 'a';

                if (!curr->children[idx]) break;

                curr = curr->children[idx];
                if (curr->isWord) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};