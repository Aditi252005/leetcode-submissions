class Solution {
public:
    bool f(TreeNode* root,int k,set<int>&st){
      if(!root) return false;
      if(st.find(k-root->val)!=st.end()) return true;
        st.insert(root->val);


      bool l=f(root->left,k,st);
      bool r=f(root->right,k,st);

      return l||r;
      
    }
    bool findTarget(TreeNode* root, int k) {
        set<int> st;
        return f(root,k,st);
    }
};