class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();

        int a=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int b=upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;

        if(a==n || nums[a]!=target) return {-1,-1};
        
        return {a,b};
        
        
    }
};