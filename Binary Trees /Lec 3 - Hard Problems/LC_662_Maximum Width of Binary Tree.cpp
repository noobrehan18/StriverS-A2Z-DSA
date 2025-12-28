/*iven the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).*/

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