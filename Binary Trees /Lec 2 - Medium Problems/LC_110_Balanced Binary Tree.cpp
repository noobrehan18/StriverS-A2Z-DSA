/*Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
*/

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
    bool isBalanced(TreeNode* root) {
        return dfh(root)!=-1;
    }
    int dfh(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lh=dfh(root->left);
        if (lh == -1) return -1;
        int rh=dfh(root->right);
         if (rh == -1) return -1;

        if(abs(lh-rh)>1){
            return -1;
        }
        return max(lh,rh)+1;
        
    }
};