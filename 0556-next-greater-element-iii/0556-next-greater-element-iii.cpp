class Solution {
public:
    int nextGreaterElement(int n) {

        vector<int> nums;
        while(n){
            nums.push_back(n%10);
            n=n/10;
        }

        reverse(nums.begin(),nums.end());
        int m=nums.size();
        int pidx=-1;
        for(int i=m-2;i>=0;i--){
            if(nums[i]<nums[i+1]) {pidx=i;break;}
        }

        if(pidx==-1) return -1;

        for(int i=m-1;i>=0;i--){
            if(nums[i]>nums[pidx]){
                swap(nums[i],nums[pidx]);
                break;
            }
        }

        reverse(nums.begin()+pidx+1,nums.end());

        int ans=0;
        for(int i=0;i<m;i++){
            if((long long)ans*10+nums[i]>INT_MAX) return -1;
            ans=ans*10+nums[i];
        }
        return ans;
    }
};