class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        vector<int> v;

        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            v.push_back(__gcd(mx,nums[i]));
        }

        sort(v.begin(),v.end());
        int l=0;
        int r=n-1;
        long long ans=0;
        while(l<r){
            ans+=__gcd(v[l],v[r]);
            l++;
            r--;
        }
        return ans;
    }
};