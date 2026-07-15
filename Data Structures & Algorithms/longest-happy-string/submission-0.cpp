class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;

        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});

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
                prev.first = prev.second;
                prev.second = nextC;
                if (--nextCount) maxHeap.push({nextCount, nextC});
            }

            ans += c;
            prev.first = prev.second;
            prev.second = c;
            if (--count) maxHeap.push({count, c});
        }

        return ans;
    }
};