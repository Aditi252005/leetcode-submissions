class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size();

        long long ans=0;
        sort(nums.begin(),nums.end());

        int i=n-1;
        while(k--){
            if(mul){
                ans+=(1LL*mul*nums[i]);
                mul--;
            }
            else ans+=nums[i];
            i--;
        }
        return ans;
    }
};