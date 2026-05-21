class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();

        int i=0;
        int j=0;

        //moving 2s to the end
        while(j<n){
            if(nums[j]!=2) {swap(nums[i],nums[j]);i++;}
            j++;
        }
       
        int k=i;
        i=0;
        j=0;
        //moving 1s to the end
        while(j<k){
            if(nums[j]!=1) {swap(nums[i],nums[j]);i++;}
            j++;
        }
    }
};