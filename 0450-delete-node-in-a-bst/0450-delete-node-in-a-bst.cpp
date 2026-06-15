class Solution {
public:
    TreeNode* f(TreeNode* root,int key){
        if(!root || root->val==key) return root;

        if(key<root->val) return f(root->left,key);
        return f(root->right,key);
    }
    TreeNode* g(TreeNode* root,TreeNode* node){
        if(!root || root->left==node || root->right==node) return root;

        if(node->val<root->val) return g(root->left,node);
        return g(root->right,node);
    }
    TreeNode* h(TreeNode* r){
        if(!r || !r->right) return r;
        return h(r->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        TreeNode* node=f(root,key);
        if(!node) return root;

        TreeNode* prev=g(root,node);

        TreeNode* rpl;
        if(!node->left) rpl=node->right;
        else if(!node->right) rpl=node->left;
        else{
            TreeNode* r=h(node->left);
            r->right=node->right;
            rpl=node->left;
        }


        if(!prev){
            return rpl;
        }
        else if(prev->left==node){ 
            prev->left=rpl;
        }else{
            prev->right=rpl;
        }

        return root;
    }
};