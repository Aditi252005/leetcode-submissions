class Solution {
public:
    int f(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
        int n=nums1.size(),m=nums2.size();
        if(i>n-1 || j>m-1) return INT_MIN;

        if(dp[i][j]!=-1) return dp[i][j];

        int take=nums1[i]*nums2[j];
        int next=f(i+1,j+1,nums1,nums2,dp);
        take=take+max(0,next);

        int s1=f(i+1,j,nums1,nums2,dp);
        int s2=f(i,j+1,nums1,nums2,dp);

        return dp[i][j]=max({take,s1,s2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return f(0,0,nums1,nums2,dp);
    }
};