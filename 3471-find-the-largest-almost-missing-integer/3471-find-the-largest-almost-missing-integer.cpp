class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        
        unordered_map<int,int> mp;
        int maxi=-1;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxi=max(maxi,nums[i]);
        }

        if(n==k) return maxi;
        if(k==1){
            while(maxi>-1 && mp[maxi]!=1) maxi--;
            return mp[maxi]==1?maxi:-1;
        }

        if(mp[nums[0]]==1 && mp[nums[n-1]]==1) return max(nums[0],nums[n-1]);
        if(mp[nums[0]]==1) return nums[0];
        if(mp[nums[n-1]]==1) return nums[n-1];
        return -1;
    }
};