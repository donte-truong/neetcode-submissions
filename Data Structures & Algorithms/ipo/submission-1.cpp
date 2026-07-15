class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<int> indices(capital.size());
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return capital[a] < capital[b];
        });

        priority_queue<int> maxHeap;
        int projects = 0;
        int i = 0;
        while (projects < k) {
            while (i < indices.size() && capital[indices[i]] <= w) {
                maxHeap.push(profits[indices[i]]);
                ++i;
            }
            if (maxHeap.empty()) break;
            w += maxHeap.top();
            maxHeap.pop();

            ++projects;
        }

        return w;
    }
};