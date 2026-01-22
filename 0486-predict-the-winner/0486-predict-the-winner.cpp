class Solution {
public:
    int f(vector<int>&nums,int i,int j,bool turn,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int op1,op2;
        if(turn){
            op1=nums[i]+f(nums,i+1,j,false,dp);
            op2=nums[j]+f(nums,i,j-1,false,dp);

            return dp[i][j]=max(op1,op2);  
        }else{
            op1=-nums[i]+f(nums,i+1,j,true,dp);
            op2=-nums[j]+f(nums,i,j-1,true,dp);
            return dp[i][j]=min(op1,op2);
        }

       
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        int tot=accumulate(nums.begin(),nums.end(),0);
        int a=f(nums,0,n-1,true,dp);
        
        if(a>=0) return true;
        return false;
    }
};