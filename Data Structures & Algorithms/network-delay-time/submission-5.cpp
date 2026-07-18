class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (const auto& time : times) {
            adj[time[0] - 1].push_back({time[1] - 1, time[2]});
        }

        priority_queue<pair<int, int>> frontier;
        frontier.push({0, k  - 1});

        vector<int> costMap(n, INT_MAX);
        costMap[k - 1] = 0;
        
        while (!frontier.empty()) {
            auto [cost, node] = frontier.top();
            frontier.pop();

            for (const auto& [nei, weight] : adj[node]) {
                int neiCost = -cost + weight;
                if (neiCost < costMap[nei]) {
                    costMap[nei] = neiCost;
                    frontier.push({-neiCost, nei}); 
                }
            }

        }

        int time = *max_element(costMap.begin(), costMap.end());
        return time == INT_MAX ? -1 : time;
    }
};
