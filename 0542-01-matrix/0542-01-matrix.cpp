class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<vector<int>> ans(n,vector<int> (m,0));
        queue<pair<pair<int,int>,int>> q;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j]){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }//else vis[i][j]=0;
            }
        }

        vector<int> dr={-1,1,0,0};
        vector<int> dc={0,0,1,-1};
        
        while(!q.empty()){
            auto curr= q.front();
            int r=curr.first.first;
            int c=curr.first.second;
            int steps=curr.second;
            
            q.pop();
            ans[r][c]=steps;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    q.push({{nr,nc},steps+1});
                    vis[nr][nc]=1;
                }
            }
           

        }

        return ans;
    }
};

//1.5 chhawal
// 1    ,2 pani,  