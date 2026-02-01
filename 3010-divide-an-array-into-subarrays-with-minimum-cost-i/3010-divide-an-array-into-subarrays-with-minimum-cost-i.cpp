class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];

        int mini1=51,mini2=51;
        for(int i=1;i<n;i++){
            if(nums[i]<mini1){
                mini2=mini1;
                mini1=nums[i];
            }
            else if(nums[i]<mini2) mini2=nums[i];
        }
        sum+=mini1+mini2;
        return sum;
       


    }
};