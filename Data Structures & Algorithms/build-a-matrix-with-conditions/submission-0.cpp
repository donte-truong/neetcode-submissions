class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rows = topoSort(k, rowConditions);
        if (rows.size() < k)
            return {};

        vector<int> cols = topoSort(k, colConditions);
        if (cols.size() < k)
            return {};

        vector<int> colIndex(k);
        for (int i = 0; i < k; ++i) {
            colIndex[cols[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int>(k));
        for (int i = 0; i < k; ++i) {
            ans[i][colIndex[rows[i]]] = rows[i] + 1;
        }
        return ans;
    }

private:
    vector<int> topoSort(int k, vector<vector<int>>& conditions) {
        vector<int> deg(k);
        vector<vector<int>> adj(k);

        for (const auto& condition : conditions) {
            deg[condition[1] - 1]++;
            adj[condition[0] - 1].push_back(condition[1] - 1);
        }

        vector<int> order;
        for (int i = 0; i < k; ++i) {
            if (deg[i] == 0)
                order.push_back(i);
        }

        int i = 0;
        while (i < order.size()) {
            int node = order[i];
            for (int& nei : adj[node]) {
                if (--deg[nei] == 0) {
                    order.push_back(nei);
                }
            }
            ++i;
        }

        return order;
    }
};