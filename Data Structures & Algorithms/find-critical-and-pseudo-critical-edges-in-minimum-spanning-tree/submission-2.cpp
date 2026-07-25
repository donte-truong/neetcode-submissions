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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i) {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(), [&](const auto& a, const auto& b) {
            return a[2] < b[2];
        });

        auto getMSTWeight = [&](int skipEdge, int forceEdge) {
            UnionFind uf(n);
            int weight = 0;
            int components = n;

            if (forceEdge != -1) {
                uf.unionSets(edges[forceEdge][0], edges[forceEdge][1]);
                components--;
                weight += edges[forceEdge][2];
            }

            for (int i = 0; i < edges.size(); ++i) {
                if (i == skipEdge)
                    continue;

                if (uf.unionSets(edges[i][0], edges[i][1])) {
                    components--;
                    weight += edges[i][2];
                }
            }

            return components == 1 ? weight : INT_MAX;
        };

        int stdWeight = getMSTWeight(-1, -1);

        vector<int> critical;
        vector<int> pseudoCritical;

        for (int i = 0; i < edges.size(); ++i) {
            if (getMSTWeight(i, -1) > stdWeight) {
                critical.push_back(edges[i][3]);
            } else if (getMSTWeight(-1, i) == stdWeight) {
                pseudoCritical.push_back(edges[i][3]);
            }
        }

        return {critical, pseudoCritical};
    }
};