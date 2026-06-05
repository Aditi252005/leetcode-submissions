class Solution {
public:
    void f(int i,vector<int>&nums,vector<int>&v,set<vector<int>>&ans){
        int n=nums.size();
        if(i>n-1){
            if(ans.find(v)==ans.end()) ans.insert(v);
            return;
        }

        //take
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            v.push_back(nums[j]);
            f(j+1,nums,v,ans);
            v.pop_back();
        }
        
        //skip
        int j=i+1;
        while(j<n && nums[j]==nums[j-1]) j++;
        f(j,nums,v,ans);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> v;
        f(0,nums,v,ans);
        vector<vector<int>> res(ans.begin(),ans.end());
        return res;
    }
};