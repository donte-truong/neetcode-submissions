class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> deg(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        for (auto& prereq : prerequisites) {
            deg[prereq[1]]++;
            adjList[prereq[0]].push_back(prereq[1]);
        }

        queue<int> nodes;
        for (int i = 0; i < numCourses; ++i) {
            if (deg[i] == 0)
                nodes.push(i);
        }

        unordered_map<int, unordered_set<int>> prereqMap;
        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();

            for (int adj : adjList[node]) {
                prereqMap[adj].insert(node);
                prereqMap[adj].insert(
                    prereqMap[node].begin(),
                    prereqMap[node].end()
                );
                if (--deg[adj] == 0)
                    nodes.push(adj);
            }
        }

        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = prereqMap[queries[i][1]].contains(queries[i][0]);
        }
        return ans;
    }
};