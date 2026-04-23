class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);

        vector<long long> ans(n,0);

        for(auto x:mp){
            vector<int>&v=x.second;
            long long s=0;
            for(auto y:v) s+=y;

            long long ls=0;
            for(int i=0;i<v.size();i++){
                long long rs= s-ls-v[i];

                long long l=1LL*i*v[i]-ls;
                long long r=rs-1LL*v[i]*(v.size()-1-i);
                ans[v[i]]=l+r;

                ls+=v[i];
            }
        }
        return ans;
    }
};