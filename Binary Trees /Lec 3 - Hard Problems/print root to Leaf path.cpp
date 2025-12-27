class Solution {
public:
    void dfs(TreeNode* root, vector<int>& path, vector<vector<int>>& res) {
        if (root == NULL) return;

        path.push_back(root->data);

        // leaf node
        if (root->left == NULL && root->right == NULL) {
            res.push_back(path);
        } 
        else {
            dfs(root->left, path, res);
            dfs(root->right, path, res);
        }

        path.pop_back(); // backtrack
    }

    vector<vector<int>> allRootToLeaf(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, path, res);
        return res;
    }
};
