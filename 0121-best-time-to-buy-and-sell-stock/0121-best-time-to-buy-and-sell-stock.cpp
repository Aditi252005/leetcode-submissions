class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        int ans=0;

        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            ans=max(ans,nums[i]-mini);
        }
        return ans;
    }
};