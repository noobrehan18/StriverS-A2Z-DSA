/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7] */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }

        return helper(preorder, 0, preorder.size() - 1,
                      inorder, 0, inorder.size() - 1, inmap);
    }

    TreeNode* helper(vector<int>& preorder, int preSt, int preEnd,
                     vector<int>& inorder, int inSt, int inEnd,
                     map<int, int>& inmap) {

        if (preSt > preEnd || inSt > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preSt]);
        int inroot = inmap[root->val];
        int numsleft = inroot - inSt;

        root->left = helper(preorder, preSt + 1, preSt + numsleft,
                             inorder, inSt, inroot - 1, inmap);

        root->right = helper(preorder, preSt + numsleft + 1, preEnd,
                              inorder, inroot + 1, inEnd, inmap);

        return root;
    }
};
