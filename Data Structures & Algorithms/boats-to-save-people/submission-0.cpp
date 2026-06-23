class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int l = 0, r = people.size() - 1;
        
        int count = 0;
        int n = 0;

        while (l < r) {
            int sum = people[l] + people[r];
            if (sum <= limit) {
                n += 1;
                l++;
            }
            n += 1;
            r--;
            count++;
        }

        return n == people.size() ? count : count + 1;
    }
};