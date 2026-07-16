class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) 
            return {0};

        vector<int> deg(n, 0);
        vector<vector<int>> adjList(n);

        for (const auto& edge : edges) {
            deg[edge[0]]++;
            deg[edge[1]]++;
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        queue<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (deg[i] == 1)
                leaves.push(i);
        }

        while (n > 2) {
            int leafCount = leaves.size();
            n -= leafCount;

            for (int i = 0; i < leafCount; ++i) {
                int node = leaves.front();
                leaves.pop();

                for (int adj : adjList[node]) {
                    if (--deg[adj] == 1)
                        leaves.push(adj);
                }
            }
        }

        vector<int> ans;
        while (!leaves.empty()) {
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};