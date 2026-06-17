class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            if (!isalnum(s[l])) {
                l++;
                continue;
            }
            if (!isalnum(s[r])) {
                r--;
                continue;
            }

            if (tolower(static_cast<unsigned char>(s[l])) != tolower(static_cast<unsigned char>(s[r]))) {
                return false;
            };

            l++; r--;
        }

        return true;
    }
};
