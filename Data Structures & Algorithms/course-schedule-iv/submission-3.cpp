class Solution {
private:
    vector<vector<int>> adjList;
    unordered_map<int, unordered_set<int>> prereqMap;

    unordered_set<int>& dfs(int course) {
        if (prereqMap.contains(course))
            return prereqMap[course];

        for (auto& next : adjList[course]) {
            dfs(next);
            for (int prereq : prereqMap[next]) {
                prereqMap[course].insert(prereq);
            }
        }
        prereqMap[course].insert(course);

        return prereqMap[course];
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adjList.resize(numCourses);
        for (auto& prereq : prerequisites) {
            adjList[prereq[0]].push_back(prereq[1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            dfs(i);
        }

        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            ans[i] = prereqMap[queries[i][0]].contains(queries[i][1]);
        }
        return ans;
    }
};