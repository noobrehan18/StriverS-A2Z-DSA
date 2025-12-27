/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]*/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*>q;    
        if(root == NULL) return ans;
        q.push(root);
        bool flag = false;

        while(!q.empty()){
            int size = q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                 TreeNode* temp = q.front();
                level.push_back(temp->val);
                 q.pop();
               if(temp->left != NULL)  q.push(temp->left);
               
               if(temp->right != NULL) q.push(temp->right);
            } 
            ans.push_back(level);
        }
        for(int i=0;i<ans.size();i++){
            if(i%2 != 0){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};