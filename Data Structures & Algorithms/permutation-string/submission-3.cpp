class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;

        vector<int> counts1(26, 0);
        vector<int> counts2(26, 0);
        for (int i{0}; i < s1.length(); ++i) {
            counts1[s1[i] - 'a'] += 1;
            counts2[s2[i] - 'a'] += 1; 
        }
        
        int matches = 0;
        for (int i{0}; i < 26; ++i) {
            matches += counts1[i] == counts2[i];
        }

        int l = 0;
        for (int r = s1.length(); r < s2.length(); ++r) {
            if (matches == 26)
                return true;

            int idx = s2[r] - 'a';
            counts2[idx] += 1;
            if (counts1[idx] == counts2[idx]) {
                matches += 1;
            } else if (counts1[idx] + 1 == counts2[idx]){
                matches -= 1;
            }

            idx = s2[l] - 'a';
            counts2[idx] -= 1;
            if (counts1[idx] == counts2[idx]) {
                matches += 1;
            } else if (counts1[idx] - 1 == counts2[idx]) {
                matches -= 1;
            }

            l += 1;
        }

        return matches == 26;
    }
};
