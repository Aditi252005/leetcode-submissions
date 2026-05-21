class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        bool check=false;

        for(int i=1;i<n;i++){
            if(check){
                if(nums[i]>nums[0]) return false;
                if(nums[i]<nums[i-1]) return false;
            }
            if(nums[i]<nums[i-1]){
                check=true;
                if(nums[i]>nums[0]) return false;
            }
        }
        return true;
    }
};