class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();

        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto& x:mp){
            sort(x.second.begin(),x.second.end());
        }

        vector<int> ans(m,-1);

        for(int i=0;i<m;i++){
            int idx=queries[i];
            int tar=nums[idx];
            int a=INT_MAX;
            vector<int>& b=mp[tar];
            if(b.size()==1) continue;
            int t=lower_bound(b.begin(),b.end(),idx)-b.begin();
            
            int s=b.size();
            int prev=(t-1+s)%s;
            int next=(t+1)%s;
            a=min({a,abs(b[t]-b[prev]),n-abs(b[t]-b[prev]),abs(b[t]-b[next]),n-abs(b[t]-b[next])});
            ans[i]=a;
        }
        return ans;
    }
};