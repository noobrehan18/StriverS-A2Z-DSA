class Solution{
	public:
		bool getp(TreeNode* root, vector<int>&arr,int x){
			if(!root){
				return false;
			}
			arr.push_back(root->val);
			if(root->val==x){
				return true;
			}
			if(getp(root->left,arr,x) || getp(root->right,arr,x)){
				return true;
			}
			arr.pop_back();
			return false;
		}
		vector<int> Solution :: solve(TreeNode* root,int b) {
			vector<int>arr;
			if(a==NULL){
				return arr;
			}
			getp(a,arr,b);
			return arr

            
		}
};