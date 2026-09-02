class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        long long sum=0;
        long long ans=0;
        while(j<n){
            mp[nums[j]]++;
            sum+=nums[j];
            while(i<j && j-i+1>k){
                mp[nums[i]]--;
                sum-=nums[i];
                i++;
            }
            while(i<j && mp[nums[j]]>1) {
                mp[nums[i]]--;
                sum-=nums[i];
                i++;
            }

            if(j-i+1==k) ans=max(ans,sum);
            j++;
        }
        return ans;
    }
};