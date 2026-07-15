class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26);

        for (char c : s) {
            int idx = c - 'a';
            freq[idx] += 1;
        }

        priority_queue<pair<int, char>> maxHeap;

        for (int i = 0; i < 26; i++) {
            if (freq[i]) maxHeap.push({freq[i], 'a' + i});
        }

        char prev = ' ';
        string ans = "";

        while (!maxHeap.empty() || prev != ' ') {
            auto [count, c] = maxHeap.top();
            maxHeap.pop();

            if (c == prev && maxHeap.empty()) {
                return "";
            }

            if (c == prev) {
                auto [nextCount, nextC] = maxHeap.top();
                maxHeap.pop();
                ans += nextC;
                if (--nextCount > 0) maxHeap.push({nextCount, nextC});
            }

            ans += c;
            if (--count > 0) maxHeap.push({count, c});
            prev = count ? c : ' ';
        }

        return ans;
    }
};