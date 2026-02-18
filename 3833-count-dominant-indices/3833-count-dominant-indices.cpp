class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n=nums.size();
        vector<int> suf(n);
        suf[n-1]=nums[n-1];
        int s=nums[n-1];
        int count=0;
        for(int i=n-2;i>=0;i--){
            suf[i]=s/(n-i-1);
            if(nums[i]>suf[i]) count++;
            s=s+nums[i];
        }
        return count;
    }
};