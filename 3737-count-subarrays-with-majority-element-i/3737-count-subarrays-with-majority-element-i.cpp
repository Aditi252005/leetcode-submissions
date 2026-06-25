class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();

        int f1=0;
        int count=0;
        for(int j=0;j<n;j++){
            if(nums[j]==target) {f1++;count++;}
            int f2=f1;
            for(int i=0;i<j;i++){
                int l=j-i+1;
                if(f2>l/2) count++;
                if(nums[i]==target) f2--;
            }
        }

        return count;
    }
};