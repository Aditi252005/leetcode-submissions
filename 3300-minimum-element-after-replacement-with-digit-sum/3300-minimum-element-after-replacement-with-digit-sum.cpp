class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();

      
        int ans=1e5;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int sum=0;
            while(num){
                sum=sum+num%10;
                num/=10;
            }
            ans=min(ans,sum);
        }
        return ans;
    }
};