class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,1e5));
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]) {
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        while(!q.empty()){
            auto[a,b]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nx=a+dr[k];
                int ny=b+dc[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    if(ans[nx][ny]>ans[a][b]+1){
                        ans[nx][ny]=1+ans[a][b];
                        q.push({nx,ny});
                    }
                }
            }


        }
        return ans;
    }
};