/*
QUESTION:

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

APPROACH:

To solve this problem, we can use the Disjoint Set data structure to group stones that share the same row or column.
- First, we find the minimum and maximum row and column values to calculate the size of the grid.
- Then, we iterate through the stones and perform the union operation for stones that share the same row or column.
- Finally, we count the number of disjoint sets and subtract it from the total number of stones to get the maximum number of stones that can be removed.

COMPLEXITY ANALYSIS:

Let n be the number of stones and m be the size of the grid.

- Building the Disjoint Set: O(n)
- Finding the number of disjoint sets: O(n)
- Overall Time Complexity: O(n)
- Space Complexity: O(n) for the Disjoint Set data structure

CODE:-
*/


class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0, maxCol = 0;
        for (auto &it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet dsu(maxRow + maxCol + 2);

        unordered_set<int> nodes;

        for (auto &it : stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1; 
            dsu.unionBySize(row, col);
            nodes.insert(row);
            nodes.insert(col);
        }
        int components = 0;
        for (auto node : nodes) {
            if (dsu.findUPar(node) == node)
                components++;
        }
        return stones.size() - components;
    }
};