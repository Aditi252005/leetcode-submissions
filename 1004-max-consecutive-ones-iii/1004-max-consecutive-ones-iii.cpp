class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();


        int i=0;
        int j=0;
        int maxl=0;

        while(j<n){
            if(nums[j]==0){
                if(k==0){
                    while(i<j && nums[i]==1) i++;
                    i++;
                } 
                else k--;
            }
            maxl=max(maxl,j-i+1);
            j++;
        }
        return maxl;
    }
};