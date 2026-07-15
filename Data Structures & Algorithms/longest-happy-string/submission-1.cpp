class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;

        if (a) maxHeap.push({a, 'a'});
        if (b) maxHeap.push({b, 'b'});
        if (c) maxHeap.push({c, 'c'});

        string ans = "";
        pair<char, char> prev = {'0', '0'};

        while (!maxHeap.empty()) {

            auto [count, c] = maxHeap.top();
            maxHeap.pop();

            if (c == prev.first && c == prev.second) {
                if (maxHeap.empty()) return ans;

                auto [nextCount, nextC] = maxHeap.top();
                maxHeap.pop();

                ans += nextC;
                if (--nextCount) maxHeap.push({nextCount, nextC});

                prev.first = prev.second;
                prev.second = nextC;
            }

            ans += c;
            if (--count) maxHeap.push({count, c});

            prev.first = prev.second;
            prev.second = c;

        }

        return ans;
    }
};