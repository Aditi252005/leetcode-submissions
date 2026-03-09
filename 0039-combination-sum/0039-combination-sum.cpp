class Solution {
public:
    void f(int i,vector<int>&candidates,int target,vector<int>&v,vector<vector<int>>&ans){
        int n=candidates.size();
        if(i>n-1 || target<0) return;
        if(target==0){
            ans.push_back(v);
            return;
        }
        
        //take
        v.push_back(candidates[i]);
        f(i,candidates,target-candidates[i],v,ans);
        v.pop_back();

        //notTake
        f(i+1,candidates,target,v,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int> v;
        f(0,candidates,target,v,ans);
        return ans;
    }
};