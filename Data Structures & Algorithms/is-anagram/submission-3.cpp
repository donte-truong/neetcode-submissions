class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> charMap(26, 0);

        for (int i = 0; i < s.length(); i++) {
            charMap[s[i]-'a']++;
            charMap[t[i] - 'a']--;
        }

        for (int num : charMap) {
            if (num != 0) {
                return false;
            }
        }
        
        return true;
    }
};
