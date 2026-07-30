class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > roomTimes;
        for (int i = 0; i < n; ++i) {
            roomTimes.push({0, i});
        }

        vector<int> count(n);
        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            while (roomTimes.top().first < start) {
                auto [_, room] = roomTimes.top();
                roomTimes.pop();
                roomTimes.push({start, room});
            }

            auto [endTime, room] = roomTimes.top();
            roomTimes.pop();
            roomTimes.push({endTime + (end - start), room});
            count[room]++;
        }

        return max_element(count.begin(), count.end()) - count.begin();
    }
};