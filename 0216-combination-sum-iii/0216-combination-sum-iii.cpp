class Solution {
public:
    void f(int i,int n,int k,vector<int>&v,vector<vector<int>>&ans){
        if(n<0) return;
        if(v.size()==k){
            if(n==0) ans.push_back(v);
            return;
        }

        for(int j=i;j<=9;j++){
            if(n-j<0) break;
            v.push_back(j);
            f(j+1,n-j,k,v,ans);
            v.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> v;
        f(1,n,k,v,ans);

        return ans;
    }
};