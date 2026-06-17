class Solution {
public:
    int appendCharacters(string s, string t) {
        int sPointer = 0;
        int tPointer = 0;

        while (sPointer < s.length() && tPointer < t.length()) {
            if (s[sPointer] == t[tPointer]) {
                tPointer++;
            }
            sPointer++;
        }

        return t.length() - tPointer;
    }
};