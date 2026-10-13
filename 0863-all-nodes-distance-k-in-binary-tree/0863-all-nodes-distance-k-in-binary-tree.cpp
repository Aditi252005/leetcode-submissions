class Solution {
public:
    void f(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&mp){
        if(!root) return;

        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;

        f(root->left,mp);
        f(root->right,mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        f(root,mp);

        vector<int> ans;
        queue<pair<int,TreeNode*>> q;
        q.push({0,target});
        unordered_set<TreeNode*> vis;

        while(!q.empty()){
            int d=q.front().first;
            TreeNode* node=q.front().second;
            q.pop();
            if(vis.find(node)!=vis.end()) continue;
            vis.insert(node);

            if(d==k) ans.push_back(node->val);
            if(d>k) break;

            if(node->left) q.push({d+1,node->left});
            if(node->right) q.push({d+1,node->right});
            if(mp[node]) q.push({d+1,mp[node]});
        }
        return ans;
    }
};