class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* newNode=new TreeNode(val);
            TreeNode* cur=root;
        }
        while(true){
            if(val>cur->val){
                if(cur->right==NULL){
                    cur->right=newNode;
                    break;
                }
                else{
                    cur=cur->right;
                }
            }
            else{
                if(cur->left==NULL){
                    cur->left=newNode;
                    break;
                }
                else{
                    cur=cur->left;
                }
            }
        }
        
    }
};