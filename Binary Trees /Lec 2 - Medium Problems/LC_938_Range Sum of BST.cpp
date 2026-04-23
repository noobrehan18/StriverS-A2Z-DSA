/*

Topics
premium lock icon
Companies
Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32 */

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return 0;
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        return root->val 
             + rangeSumBST(root->left, low, high) 
             + rangeSumBST(root->right, low, high);
    }
};