class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int p=1;

        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            p=p*nums[i];
            ans=max({ans,p,nums[i]});
            if(p==0) p=1;
        }
        p=1;
        for(int i=n-1;i>=0;i--){
            p=p*nums[i];
            ans=max({ans,p});
            if(p==0) p=1;
        }
        return ans;
    }
};