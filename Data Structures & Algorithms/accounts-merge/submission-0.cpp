class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 1);
        iota(parent.begin(), parent.end(), 0);
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

        if (rootp == rootq) return false;

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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);

        unordered_map<string, int> emailToAcc;

        for (int i = 0; i < n; ++i) {
            vector<string> account = accounts[i];
            for (int j = 1; j < account.size(); j++) {
                string email = account[j];
                if (emailToAcc.contains(email)) {
                    uf.unionSets(emailToAcc[email], i);
                }
                emailToAcc[email] = i;
            }
        }

        unordered_map<int, vector<string>> emailGroup;
        for (const auto& [email, accId] : emailToAcc) {
            int leader = uf.find(accId);
            emailGroup[leader].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto& [idx, emails] : emailGroup) {
            sort(emails.begin(), emails.end());
            vector<string> account(emails.size() + 1);
            account[0] = accounts[idx][0];
            for (int i = 1; i <= emails.size(); ++i) {
                account[i] = emails[i - 1];
            }
            ans.push_back(account);
        }

        return ans;
    }
};