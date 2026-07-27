class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(nums[i]-1>a) {b=a;a=nums[i]-1;}
            else if(nums[i]-1>b) b=nums[i]-1;
        }
        return a*b;
    }
};