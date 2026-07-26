class Solution {
public:
    string predictPartyVictory(string senate) {
        int count = 0;

        int i = 0;
        while (i < senate.size()) {
            if (senate[i] == 'R') {
                if (count < 0)
                    senate.push_back('D');
                count++;
            } else {
                if (count > 0)
                    senate.push_back('R');
                count--;
            }
            i++;
        }

        return count > 0 ? "Radiant" : "Dire";
    }
};