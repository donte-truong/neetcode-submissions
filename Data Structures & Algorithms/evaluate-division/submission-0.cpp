class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<double, string>>> adj;

        for (int i{0}; i < equations.size(); ++i) {
            string numerator = equations[i][0];
            string denominator = equations[i][1];
            adj[numerator].push_back({values[i], denominator});
            adj[denominator].push_back({1/values[i], numerator});
        }

        vector<double> ans(queries.size());
        for (int i{0}; i < queries.size(); ++i) {
            string source = queries[i][0];
            string target = queries[i][1];

            unordered_set<string> visited;
            ans[i] = dfs(adj, source, target, visited);
        }
        return ans;
    }

private:
    double dfs(
        unordered_map<string, vector<pair<double, string>>>& adj,
        string source,
        string target,
        unordered_set<string>& visited
    ) {
        if (!adj.contains(source) || !adj.contains(target))
            return -1.0;

        if (source == target)
            return 1.0;

        visited.insert(source);
        for (const auto& [val, neighbor] : adj[source]) {
            if (visited.contains(neighbor)) continue;
            double adjVal = dfs(adj, neighbor, target, visited);
            if (adjVal != -1.0)
                return val * adjVal;
        }
        return -1.0;
    }
};