class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int n=nums.size();

        int ans=0;
        for(int i=0;i<n;i++){
            int f;
            if(nums[i]<10) f=nums[i];
            else if(nums[i]<100) f=nums[i]/10;
            else if(nums[i]<1000) f=nums[i]/100;
            else if(nums[i]<10000) f=nums[i]/1000;
            for(int j=i+1;j<n;j++){
                int s= nums[j]%10;
                if(gcd(f,s)==1) ans++;
            }
        }
        return ans;
    }
};