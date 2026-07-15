class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> events;

        for (auto& trip : trips) {
            events.push_back({trip[1], trip[0]});
            events.push_back({trip[2], -trip[0]});
        }

        sort(events.begin(), events.end(), [&](auto a, auto b) {
            return a.first < b.first || (
                a.first == b.first && a.second < b.second
            );
        });

        int count = 0;
        for (auto& event : events) {
            count += event.second;
            if (count > capacity) return false;
        }

        return true;
    }
};