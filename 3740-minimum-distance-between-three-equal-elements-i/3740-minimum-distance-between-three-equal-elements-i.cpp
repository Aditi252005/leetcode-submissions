class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);

        int ans=INT_MAX;
        for(auto x:mp){
            vector<int> v=x.second;
            if(v.size()>=3){
                sort(v.begin(),v.end());
                for(int i=0;i<v.size()-2;i++) ans=min(ans,abs(v[i]-v[i+1])+abs(v[i+1]-v[i+2])+abs(v[i]-v[i+2]));
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};