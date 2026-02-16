class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        int maxf=0;
        for(auto it:nums){
            mp[it]++;
            maxf=max(maxf,mp[it]);
        }
        cout<<maxf;
        vector<vector<int>> a(maxf+1);

        for(auto it:mp){
            a[it.second].push_back(it.first);
        }

        for(int i=0;i<n;i++){
            int f=mp[nums[i]];
            if(a[f].size()==1) return nums[i];
        }
        return -1;
    }
};