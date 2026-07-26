class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = ratings.size();
        int i = 1;
        while (i < ratings.size()) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int inc = 0;
            while (i < ratings.size() && ratings[i] > ratings[i - 1]) {
                inc++;
                ans += inc;
                i++;
            }

            int dec = 0;
            while (i < ratings.size() && ratings[i] < ratings[i - 1]) {
                dec++;
                ans += dec;
                i++;
            }

            ans -= min(inc, dec);
        }

        return ans;
    }
};