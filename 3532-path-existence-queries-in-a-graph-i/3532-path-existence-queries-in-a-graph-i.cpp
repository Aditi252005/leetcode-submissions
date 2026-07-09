class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxd, vector<vector<int>>& queries) {
        vector<int> parent(n,-1);

        int l;
        for(int i=0;i<n;i++){
            if(parent[i]==-1) parent[i]=i;
            
            int idx= upper_bound(nums.begin(),nums.end(),nums[i]+maxd) - nums.begin();

            if(parent[min(n-1,idx-1)]!=-1) continue;
            for(int j=i+1;j<min(n,idx);j++) parent[j]=parent[i];
           
        }

        vector<bool> ans(queries.size());
        int k=0;
        for(auto q:queries){
            int i=q[0];
            int j=q[1];
            if(parent[i]==parent[j]) ans[k]=true;
            else ans[k]=false;
            k++;
        }

        return ans;
    }
};