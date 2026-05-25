class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();

        int lo=1;
        int hi=*max_element(nums.begin(),nums.end());

        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            int a=0;
            for(int i=0;i<n;i++){
                if(a>threshold) break;
                if(nums[i]%mid==0) a+=nums[i]/mid;
                else a+= nums[i]/mid +1;
            }

            if(a<=threshold) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};