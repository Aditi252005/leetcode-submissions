class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mul=k;

        for(int i=0;i<n;i++){
            
            if(nums[i]>mul) return mul;
            else if(nums[i]<mul) continue;
            else mul+=k;
        }
        return mul;
    }
};