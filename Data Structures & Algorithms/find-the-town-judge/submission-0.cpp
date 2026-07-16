class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, unordered_set<int>> outgoing;
        unordered_map<int, unordered_set<int>> incoming;

        for (auto& t : trust) {
            outgoing[t[0]].insert(t[1]);
            incoming[t[1]].insert(t[0]);
        }

        for (int i = 1; i <= n; ++i) {
            if (outgoing[i].size() == 0 && incoming[i].size() == (n - 1))
                return i;
        }

        return -1;
    }
};