class Solution {
public:
    void f(int i,vector<int>&nums,vector<int>&v,vector<vector<int>>&ans){
        int n=nums.size();
       
        ans.push_back(v);
         

        //take
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            v.push_back(nums[j]);
            f(j+1,nums,v,ans);
            v.pop_back();
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        f(0,nums,v,ans);
        return ans;
    }
};