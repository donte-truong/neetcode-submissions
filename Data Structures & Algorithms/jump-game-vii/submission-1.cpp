class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<bool> canReach(n, false);

        if (s[n - 1] == '1') return false;
        canReach[n - 1] = true;

        for (int i{n - 2}; i >= 0; --i) {
            if (s[i] == '1') continue;
            for (int j{i + minJump}; j < n && j <= i + maxJump; ++j) {
                if (canReach[j]) {
                    canReach[i] = true;
                    break;
                }
            }
        }
        
        return canReach[0];
    }
};