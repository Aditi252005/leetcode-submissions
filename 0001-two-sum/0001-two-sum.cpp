class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]=i;

        for(int i=0;i<n;i++){
            int tar=target-nums[i];
            if(mp.find(tar)!=mp.end() && mp[tar]!=i) return {i,mp[tar]};
        }
        return {0,0};
    }
};