class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            
            if(!node && q.empty()) {ans.push_back(v);break;}
            if(!node) {ans.push_back(v);q.push(NULL);v={};continue;}
            v.push_back(node->val);

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return ans;
    }
};