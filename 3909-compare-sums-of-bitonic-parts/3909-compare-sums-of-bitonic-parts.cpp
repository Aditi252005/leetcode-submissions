class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n=nums.size();
        long long as=0,ds=0;

        int i=0;
        while(i<n){
            if(nums[i]<nums[i+1]) {as+=nums[i];i++;}
            else break;  
        }
        i++;
        while(i<n){
            ds=ds+=nums[i];
            i++;
        }
       
        if(as>ds) return 0;
        else if(as<ds) return 1;
        return -1;
        
    }
};