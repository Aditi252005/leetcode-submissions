class Solution {
public:
    string s="",t="";
    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
       
        if(!root) return NULL;
        if(root->val==p || root->val==q) return root;
        
        TreeNode* l=lowestCommonAncestor(root->left,p,q);
        TreeNode* r=lowestCommonAncestor(root->right,p,q);

        if(l && r) return root;
        return l?l:r;
        
    }
    int f(TreeNode* root,int st){
        if(!root) return 0;
        if(root->val==st) return 1;

        int l=f(root->left,st);
        int r=f(root->right,st);
        
        if(l) return l+1;
        if(r) return r+1;

        return 0;
    }
    string g(TreeNode* root,int dt){
        if(!root) return "";
        if(root->val==dt) return t;

        t.push_back('L');
        string l=g(root->left,dt);
        if(l!="") return l;
        t.pop_back();
        t.push_back('R');
        string r=g(root->right,dt);
        if(r!="") return r;
        t.pop_back();

        return "";
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {

        t="";
        TreeNode* lcs=lowestCommonAncestor(root,startValue,destValue);
        int l=f(lcs,startValue);
        string s(l-1,'U');
        t=g(lcs,destValue);

        return s+t;
    }
};