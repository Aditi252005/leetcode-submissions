class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;

        int ans=0;
        int mini=INT_MAX;
        int maxi=INT_MIN;

        int a,b;
        for(int i=0;i<n;i++){
            if(nums[i]<mini) {mini=nums[i];a=i;}
            if(nums[i]>maxi) {maxi=nums[i];b=i;}
        }

        if(a<b){
            ans=min({b,n-a-1,a+n-b})+1;
        }else{
            ans=min({a,n-b-1,b+n-a})+1;
        }

        return ans;
    }
};