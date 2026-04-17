class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;

        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            int f=nums[i];
            int r=0;
            while(f>0){
                r=r*10+f%10;
                f=f/10;
            }
            if(mp.count(nums[i])) ans=min(ans,i-mp[nums[i]]);
           
            mp[r]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};