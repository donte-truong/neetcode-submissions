class UnionFind {
private:
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
            rank[rootp]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);

        unordered_map<string, int> emailToAcc;

        for (int i{0}; i < accounts.size(); ++i) {
            vector<string>& account = accounts[i];
            for (int j{1}; j < account.size(); ++j) {
                if (emailToAcc.contains(account[j])) {
                    uf.unionSets(i, emailToAcc[account[j]]);
                }
                emailToAcc[account[j]] = i;
            }
        }

        unordered_map<int, vector<string>> emailGroups;

        for (const auto& [email, acc] : emailToAcc) {
            int leader = uf.find(acc);
            emailGroups[leader].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto& [acc, emails] : emailGroups) {
            vector<string> account(emails.size() + 1);
            account[0] = accounts[acc][0];

            for (int i{1}; i <= emails.size(); ++i) {
                account[i] = emails[i - 1];
            }
            ans.push_back(account);
        }
        return ans;
    }
};