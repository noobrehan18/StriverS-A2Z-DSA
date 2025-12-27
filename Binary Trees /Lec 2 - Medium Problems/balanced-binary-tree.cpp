//brute force approach
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int lh=isBalanced(root->left);
        int rh=isBalanced(root->right);
        if(abs(rh-lh)>1){
            return false;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);

        if(!left || right){
            return false;
        }
        return true;
        
    }
};

//optimized approach
