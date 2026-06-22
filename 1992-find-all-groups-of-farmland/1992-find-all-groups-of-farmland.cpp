class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&land,vector<int>&v){
        int n=land.size();
        int m=land[0].size();

        if(i<0 || j<0 || i>n-1 || j>m-1 || !land[i][j]) return;
        land[i][j]=0;

        v[2]=max(v[2],i);
        v[3]=max(v[3],j);

        dfs(i+1,j,land,v);
        dfs(i,j+1,land,v);
        dfs(i-1,j,land,v);
        dfs(i,j-1,land,v);

    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]){
                    vector<int> v={i,j,0,0};
                    dfs(i,j,land,v);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};