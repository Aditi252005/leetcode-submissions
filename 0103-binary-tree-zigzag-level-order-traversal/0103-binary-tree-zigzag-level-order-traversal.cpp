class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> v;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        bool check=false;

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(!node && q.empty()){
                if(check) reverse(v.begin(),v.end());
                ans.push_back(v);
                break;
            }
            if(!node){
                if(check) reverse(v.begin(),v.end());
                ans.push_back(v);
                v={};
                q.push(NULL);
                check=!check;
                continue;
            }
            v.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return ans;
    }
};