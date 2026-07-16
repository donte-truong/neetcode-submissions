class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> cmap;
        for (int i = 0; i < order.size(); ++i) {
            cmap[order[i]] = i;
        }

        for (int i = 1; i < words.size(); ++i) {
            string word1 = words[i - 1];
            string word2 = words[i];

            for (int j = 0; j < word1.length(); ++j) {
                char c1 = word1[j];
                if (j >= word2.length()) return false;
                char c2 = word2[j];

                if (c1 != c2) {
                    if (cmap[c2] < cmap[c1]) return false;
                    break;
                }
            }
        }

        return true;
    }
};