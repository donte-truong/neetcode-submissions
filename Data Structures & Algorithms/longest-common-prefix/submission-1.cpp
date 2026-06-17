class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];

        for (const auto& str : strs) {
            int i = 0;
            while (i < min(str.size(), prefix.size())) {
                if (prefix[i] != str[i]) break;
                i++;
            }
            prefix.erase(i);
        }

        return prefix;
    }
};