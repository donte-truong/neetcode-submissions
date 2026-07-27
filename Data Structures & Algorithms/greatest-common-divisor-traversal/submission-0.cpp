class UnionFind {
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(size);
    }

    int find(int p) {
        if (parent[p] != p) {
            parent[p] = find(parent[p]);
        }
        return parent[p];
    }

    bool unionSets(int p, int q) {
        int rootp = find(p);
        int rootq = find(q);

        if (rootp == rootq)
            return false;

        if (rank[rootp] < rank[rootq]) {
            parent[rootp] = rootq;
        } else if (rank[rootp] > rank[rootq]) {
            parent[rootq] = rootp;
        } else {
            parent[rootp] = rootq;
            rank[rootq]++;
        }

        return true;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size() == 1)
            return true;

        int maxNum = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1)
                return false;

            maxNum = max(nums[i], maxNum);
        }

        vector<int> sieve(maxNum + 1, 0);
        for (int n = 2; n * n <= maxNum; ++n) {
            if (sieve[n] == 0) {
                for (int i = n * n; i <= maxNum; i += n) {
                    if (sieve[i] == 0)
                        sieve[i] = n;
                }
            }
        }

        UnionFind uf(nums.size() + maxNum + 1);
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] > 1) {
                if (sieve[nums[i]] == 0) {
                    uf.unionSets(i, nums.size() + nums[i]);
                    break;
                }

                uf.unionSets(i, nums.size() + sieve[nums[i]]);
                nums[i] /= sieve[nums[i]];
            }
        }

        int root = uf.find(0);
        for (int i = 1; i < nums.size(); ++i) {
            if (uf.find(i) != root)
                return false;
        }
        return true;
    }
};