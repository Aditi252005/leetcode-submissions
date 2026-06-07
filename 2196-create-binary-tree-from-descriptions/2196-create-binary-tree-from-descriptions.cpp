class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        int n=d.size();
        set<int> st;
        map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<n;i++){
            mp[d[i][0]].push_back({d[i][1],d[i][2]});
            st.insert(d[i][1]);
        }

        int r;
        for(int i=0;i<n;i++){
            if(st.find(d[i][0])==st.end()) r=d[i][0];
        }

        TreeNode* root= new TreeNode(r);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto p=q.front();
            vector<pair<int,int>> v=mp[p->val];
            q.pop();

            int i=0;
            while(i<v.size()){
                TreeNode * node = new TreeNode(v[i].first);
                if(v[i].second==1){
                    p->left=node;
                }else{
                    p->right=node;
                }
                q.push(node);
                i++;
            }
        }

        return root;
    }
};