class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiants;
        queue<int> dires;

        for (int i = 0; i < senate.length(); ++i) {
            if (senate[i] == 'R') {
                radiants.push(i);
            } else {
                dires.push(i);
            }
        }

        int i = senate.length();
        while (!radiants.empty() && !dires.empty()) {
            if (radiants.front() < dires.front()) {
                dires.pop();
                radiants.pop();
                radiants.push(i);
            } else {
                radiants.pop();
                dires.pop();
                dires.push(i);
            }
            i++;
        }

        return !radiants.empty() ? "Radiant" : "Dire";
    }
};