class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        const int n = tasks.size();

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return tasks[a][0] < tasks[b][0] || (
                tasks[a][0] == tasks[b][0] && a < b
            );
        });

        auto comp = [&](int a, int b) {
            return tasks[a][1] > tasks[b][1] || (
                tasks[a][1] == tasks[b][1] && a > b
            );
        };
        priority_queue<int, vector<int>, decltype(comp)> minHeap(comp);

        int time = 1;
        int i = 0;
        vector<int> ans;

        while (!minHeap.empty() || i < n) {

            while (i < n && tasks[indices[i]][0] <= time) {
                minHeap.push(indices[i]);
                i++;
            }

            if (minHeap.empty()) {
                time = tasks[indices[i]][0];
            } else {
                int taskIdx = minHeap.top();
                minHeap.pop();

                ans.push_back(taskIdx);
                time += tasks[taskIdx][1];
            }

        }

        return ans;

    }
};