class Solution {
public:
    void findingParent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent){
        if(!root) return;

        if(root->left) parent[root->left]=root;
        if(root->right) parent[root->right]=root;

        findingParent(root->left,parent);
        findingParent(root->right,parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        findingParent(root,parent);

        vector<int> ans;
        queue<pair<int,TreeNode*>> q;
        unordered_set<TreeNode*> vis;
        q.push({k,target});

        while(!q.empty()){
            int dis=q.front().first;
            TreeNode* node= q.front().second;
            q.pop();

            if(vis.find(node)!=vis.end()) continue;
            vis.insert(node);

            if(dis==0) ans.push_back(node->val);

            if(node->left) q.push({dis-1,node->left});
            if(node->right) q.push({dis-1,node->right});
            if(parent[node]) q.push({dis-1,parent[node]});
        }
        return ans;
    }
};