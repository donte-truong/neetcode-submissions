class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int g = __gcd(str1.length(), str2.length());
        if (str1.length() < str2.length()) {
            swap(str1, str2);
        }

        for (int i = 0; i < str1.length(); ++i) {
            if (str1[i] != str1[i % g] || (i < str2.length() && str2[i] != str1[i % g]))
                return "";
        }

        return str1.substr(0, g);
    }
};