class Solution {
  public:
    
    int inOrderSuccessor(Node *root, Node *x) {
       Node* suc=NULL;
       while(root!= NULL){
           if(x->data>= root->data){
               root=root->right;
           }
           else{
               suc=root;
               root=root->left;
           }
       }
       if(suc==NULL){
               return -1;
           }
       return suc->data;
        
    }
};
//.  inorderPredecessor code
class Solution {
public:
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {

        TreeNode* predecessor = NULL;
        while(root != NULL){
            if(root->val >= p->val){
                root = root->left;
            }
            else{
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
    }
};
