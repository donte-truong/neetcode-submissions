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

        vector<int> q;
        for (int i = 0; i < k; ++i) {
            if (deg[i] == 0) {
                q.push_back(i);
            }
        }

        int i = 0;
        while (i < q.size()) {
            for (int& nei : adj[q[i]]) {
                if (--deg[nei] == 0)
                    q.push_back(nei);
            }
            ++i;
        }

        return q;
    }
};