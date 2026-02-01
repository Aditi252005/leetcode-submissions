class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        int a=nums[n-1];

        for(int i=n-2;i>=0;i--){
            if(nums[i]>=a) return i+1;
            a=nums[i];
        }
        return 0;
    }
};