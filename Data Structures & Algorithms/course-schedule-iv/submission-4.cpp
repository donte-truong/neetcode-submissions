class Solution {

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> deg(numCourses, 0);
        vector<vector<int>> adjList(numCourses);

        unordered_map<int, unordered_set<int>> prereqMap;

        for (auto& prereq : prerequisites) {
            adjList[prereq[0]].push_back(prereq[1]);
            deg[prereq[1]]++;
        }

        queue<int> nodes;
        for (int i = 0; i < numCourses; ++i) {
            if (deg[i] == 0)
                nodes.push(i);
        }

        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();
            for (int next : adjList[node]) {
                prereqMap[next].insert(node);
                prereqMap[next].insert(prereqMap[node].begin(), prereqMap[node].end());
                if (--deg[next] == 0)
                    nodes.push(next);
            }
        }

        vector<bool> ans(queries.size());

        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = prereqMap[queries[i][1]].contains(queries[i][0]);
        }

        return ans;
    }
};