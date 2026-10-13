class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        bool check=false;

        while(!q.empty()){
            int sz=q.size();

            while(sz--){
                TreeNode* node=q.front();
                q.pop();
                v.push_back(node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }

            if(check) reverse(v.begin(),v.end());
            ans.push_back(v);
            v={};
            check=!check;            
        }
        return ans;
        
    }
};