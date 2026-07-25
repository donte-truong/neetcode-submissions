class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> valueMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
            {' ', 0}
        };
        
        int value = 0;
        char prev = ' ';
        for (char& c : s) {
            if (
                (prev == 'I' && (c == 'V' || c == 'X')) ||
                (prev == 'X' && (c == 'L' || c == 'C')) ||
                (prev == 'C' && (c == 'D' || c == 'M'))
            ) {
                value -= 2 * valueMap[prev];
            }
            prev = c;
            value += valueMap[c];
        }
        
        return value;
    }
};