class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        while (l <= r) {

            int m = l + (r - l) / 2;

            if (shippable(weights, days, m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }

        }

        return l;

    }

private:
    bool shippable(vector<int>& weights, int limit, int capacity) {

        int ships = 1;
        int currCap = capacity;

        for (int& weight : weights) {

            if (currCap - weight < 0) {
                if (++ships > limit) return false;
                currCap = capacity;
            }
            currCap -= weight;

        }

        return ships <= limit;

    }
};