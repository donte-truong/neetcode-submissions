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
    Node* oneLeaf = new Node(1, true);
    Node* zeroLeaf = new Node(0, true);

    Node* subconstruct(vector<vector<int>>& grid, int u, int d, int l, int r) {
        if (u == d - 1 && l == r - 1) {
            return grid[u][l] == 1 ? oneLeaf : zeroLeaf;
        }

        int mv = u + (d - u) / 2;
        int mh = l + (r - l) / 2;

        Node* topLeft = subconstruct(grid, u, mv, l, mh);
        Node* topRight = subconstruct(grid, u, mv, mh, r);
        Node* bottomLeft = subconstruct(grid, mv, d, l, mh);
        Node* bottomRight = subconstruct(grid, mv, d, mh, r);

        if (
            topLeft->isLeaf &&
            topRight->isLeaf &&
            bottomLeft->isLeaf &&
            bottomRight->isLeaf &&
            topLeft->val == topRight->val && 
            bottomLeft->val == bottomRight->val && 
            topRight->val == bottomLeft->val
        ) {
            return topLeft;
        }

        return new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        if (grid.size() == 0) return new Node(1, true);
        return subconstruct(grid, 0, grid.size(), 0, grid.size());
    }
};