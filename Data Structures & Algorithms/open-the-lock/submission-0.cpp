class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> invalid;
        for (string& deadend : deadends) {
            invalid.insert(deadend);
        }

        priority_queue<pair<int, string>> combinations;
        combinations.push({0, "0000"});

        unordered_map<string, int> costMap;
        costMap["0000"] = 0;

        while (!combinations.empty()) {
            auto [cost, combination] = combinations.top();
            combinations.pop();

            if (combination == target)
                return -cost;

            if (invalid.contains(combination))
                continue;

            for (int i = 0; i < 4; ++i) {
                string up = combination;
                up[i] = ((up[i] - '0' + 1) % 10) + '0';

                if (!costMap.contains(up) || -cost + 1 < costMap[up]) {
                    combinations.push({cost - 1, up});
                    costMap[up] = -cost + 1;
                }

                string down = combination;
                down[i] = ((down[i] - '0' + 9) % 10) + '0';

                if (!costMap.contains(down) || -cost + 1 < costMap[down]) {
                    combinations.push({cost - 1, down});
                    costMap[down] = -cost + 1;
                }
            }
        }

        return -1;
    }
};