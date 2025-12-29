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
    int cnt=0;
    int kthSmallest(TreeNode* root, int k) {
        if(root== NULL){
            return -1;
        }
        if(root->left){
            int lAns=kthSmallest(root->left,k);
            if(lAns !=-1){
                return lAns;
            }
        }
        if(cnt+1==k){
            return root->val;
        }
        cnt=cnt+1;
        if(root->right){
            int rAns=kthSmallest(root->right,k);
            if(rAns !=-1){
                return rAns;
            }
        }
        return -1;
    }
};