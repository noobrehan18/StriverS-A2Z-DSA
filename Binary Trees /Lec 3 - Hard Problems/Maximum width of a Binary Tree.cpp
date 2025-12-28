class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int maxwidth=0;

        while(q.size()>0){
            int curlevelsize=q.size();
            long long stidx=q.front().second;
            long long endidx=q.back().second;
            maxwidth=max(maxwidth,int(endidx-stidx+1));

            for(int i=0;i<curlevelsize;i++){
                auto curr=q.front();
                q.pop();
                long long idx = curr.second - stidx;
                if(curr.first->left){
                    q.push({curr.first->left,idx*2+1});
                }
                if(curr.first->right){
                    q.push({curr.first->right,idx*2+2});
                }
            }


        }
        return maxwidth;      
    }
};