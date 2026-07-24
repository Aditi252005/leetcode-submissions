class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        vector<int> st(2048,0);
        vector<int> dp(2048,0);
        for(int j=0;j<n;j++){
            for(int k=j;k<n;k++) dp[nums[j]^nums[k]]=1;
        } 

        for(int i=0;i<n;i++){
            for(int k=0;k<2048;k++){
                if(dp[k]) st[nums[i]^k]=1;
            }
        }

        int ans=0;
        for(auto x:st) if(x) ans++;
        return ans;
    }
};