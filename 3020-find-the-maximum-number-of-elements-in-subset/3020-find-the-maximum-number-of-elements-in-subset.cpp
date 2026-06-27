class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        map<long long,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;

        int ans=1;
        if(mp.find(1)!=mp.end()){
            if(mp[1]%2==0) ans=mp[1]-1;
            else ans=mp[1];
        }

        for(auto&[x,f] :mp){
            if(x==1) continue;
            int l=0;

            long long curr=x;

            while(mp[curr]>=2){
                l+=2;
                curr=curr*curr;
            }

            if(mp[curr]==1) l++;
            else if(l>0) l--;

            ans=max(ans,l);
        }
        return ans;
    }
};