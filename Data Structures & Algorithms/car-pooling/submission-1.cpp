class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int first = INT_MAX;
        int last = 0;

        for (auto& trip : trips) {
            first = min(trip[1], first);
            last = max(trip[2], last);
        }

        int range = last - first + 1;

        vector<int> events(range, 0);

        for (auto& trip : trips) {
            events[trip[1] - first] += trip[0];
            events[trip[2] - first] -= trip[0];
        }

        int count = 0;
        for (int passengers : events) {
            count += passengers;
            if (count > capacity) return false;
        }
        return true;
    }
};