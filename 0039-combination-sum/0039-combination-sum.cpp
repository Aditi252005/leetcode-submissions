class Solution {
public:
    void f(int i,vector<int>&c,int t,vector<int>&v,vector<vector<int>>&ans){
        int n=c.size();
        if(i>n-1) return;
        if(t<0) return;
        if(t==0){
            ans.push_back(v);
            return;
        }

        for(int j=i;j<n;j++){
            v.push_back(c[j]);
            f(j,c,t-c[j],v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
       int n=c.size();
       sort(c.begin(),c.end());

       vector<int> v;
       vector<vector<int>> ans;

       f(0,c,t,v,ans);
       return ans;

    }
};