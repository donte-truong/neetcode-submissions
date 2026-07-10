/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* subconstruct(vector<vector<int>>& grid, int l, int r, int u, int d) {
        if (r == l + 1 && d == u + 1) {
            return new Node(grid[l][u], true);
        }

        int val = grid[l][u];
        cout << l << " " << r << " " << u << " " << d << endl;
        for (int i = l; i < r; i++) {
            for (int j = u; j < d; j++) {
                if (grid[i][j] != val) {
                    int mh = l + (r - l) / 2;
                    int mv = u + (d - u) / 2;
                    Node* topLeft = subconstruct(grid, l, mh, u, mv);
                    Node* topRight = subconstruct(grid, l, mh, mv, d);
                    Node* bottomLeft = subconstruct(grid, mh, r, u, mv);
                    Node* bottomRight = subconstruct(grid, mh, r, mv, d);
                    return new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
                }
            }
        }

        return new Node(grid[l][u], true);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.size() == 0) return new Node(1, true);

        return subconstruct(grid, 0, grid.size(), 0, grid[0].size());
    }
};