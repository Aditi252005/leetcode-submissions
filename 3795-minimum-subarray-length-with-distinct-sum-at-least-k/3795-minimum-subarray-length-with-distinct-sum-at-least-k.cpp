class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;

        int i=0;
        int j=0;
        int minl=INT_MAX;
        int sum=0;

        while(j<n){
            if(mp[nums[j]]==0) sum+=nums[j];//
            mp[nums[j]]++;
            
           
            while(sum>=k){
                minl=min(minl,j-i+1);
                mp[nums[i]]--;
                if(mp[nums[i]]==0) sum-=nums[i];//
                i++;
            }
            
            j++;

        }
        if(minl==INT_MAX) return -1;
        return minl;
    }
    // 2 3 2 3 1   k=6
};