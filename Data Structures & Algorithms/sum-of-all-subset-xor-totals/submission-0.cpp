class Solution {

private:
    vector<int> subsets = {0};

public:
    int subsetXORSum(vector<int>& nums) {
        for (int num : nums) {
            subsets.reserve(subsets.size() * 2);
            vector<int> newSubsets(subsets.size());
            for (int i = 0; i < subsets.size(); i++) {
                int subset = subsets[i];
                newSubsets[i] = subset ^ num;
            }
            subsets.insert(subsets.end(), newSubsets.begin(), newSubsets.end());
        }

        return accumulate(subsets.begin(), subsets.end(), 0);
    }
};