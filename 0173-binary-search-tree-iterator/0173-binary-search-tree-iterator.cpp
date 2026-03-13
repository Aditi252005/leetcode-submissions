/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> v;
    int i=-1;
    int n;
    void f(TreeNode* root){
        if(!root) return;
        f(root->left);
        v.push_back(root->val);
        f(root->right);
    }
    BSTIterator(TreeNode* root) {
        //v=[];
        f(root);
        n=v.size();
    }
    
    int next() {
       i=i+1;
       return v[i];
    }
    
    bool hasNext() {
        if(i+1<n) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */