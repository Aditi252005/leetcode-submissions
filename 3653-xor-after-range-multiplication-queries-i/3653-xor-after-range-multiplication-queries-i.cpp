class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        const int mod=1000000007;
        int j=0;
        while(j<m){
            auto curr=queries[j];
            int l=curr[0];
            int r=curr[1];
            int k=curr[2];
            int v=curr[3]; 
            
            for(int i=l;i<=r;i+=k){
                long long num=nums[i];
                nums[i]=((num%mod)*v)%mod;
            }
            j++;
        }

        int ans=0;
        for(int i=0;i<n;i++) ans=ans^nums[i];
        return ans;
    }
};