class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n, 0);
        vector<int> numMeetings(n, 0);

        sort(meetings.begin(), meetings.end());

        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            int minTime = 0;
            bool delay = true;
            for (int i{0}; i < rooms.size(); ++i) {
                if (rooms[i] < rooms[minTime])
                    minTime = i;

                if (rooms[i] <= start) {
                    rooms[i] = end;
                    numMeetings[i] += 1;
                    delay = false;
                    break;
                }
            }

            if (delay) {
                rooms[minTime] += end - start;
                numMeetings[minTime] += 1;
            }
        }

        int m = 0;
        for (int i{1}; i < numMeetings.size(); ++i) {
            if (numMeetings[i] > numMeetings[m])
                m = i;
        }
        return m;
    }
};