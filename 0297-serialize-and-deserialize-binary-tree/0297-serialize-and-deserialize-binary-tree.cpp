class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null";
        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node){
                ans+=to_string(node->val);
                ans.push_back(',');
                q.push(node->left);
                q.push(node->right);
            }
            else ans+="null,";
        }

        return ans;
    }
   
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.size();
        if(data.substr(0,4)=="null") return NULL;

        int i=0;
        string curr;
        while(i<n && data[i]!=',') {curr+=data[i];i++;}
        i++;
        
        TreeNode* root=new TreeNode(stoi(curr));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty() && i<data.length()){
            TreeNode* node=q.front();
            q.pop();

            curr="";
            while(i<n && data[i]!=',') {curr+=data[i];i++;}
            i++;

            if(curr!="null"){
                node->left=new TreeNode(stoi(curr));
                q.push(node->left);
            } 


            curr="";
            while(i<n && data[i]!=',') {curr+=data[i];i++;}
            i++;

            if(curr!="null"){
                node->right=new TreeNode(stoi(curr));
                q.push(node->right);
            } 
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));