class Solution {
public:
    long long dfs(TreeNode* root){
        if(!root) return 0;
        return root->val+dfs(root->left)+dfs(root->right);
    }
    long long dfs2(TreeNode* root, long long tot, long long& ans){
        if(!root) return 0;

        long long left = dfs2(root->left, tot, ans);
        long long right = dfs2(root->right, tot, ans);

        long long subSum = root->val + left + right;
        ans = max(ans, subSum * (tot - subSum));

        return subSum;
    }
    int maxProduct(TreeNode* root) {
        long long tot=dfs(root);
        long long ans=0;
        dfs2(root,tot,ans);
        return ans%1000000007;
    }
};