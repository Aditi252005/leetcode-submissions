class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       int fo=0;

       queue<pair<int,int>> q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }else if(grid[i][j]==1) fo++;
        }
       } 
       q.push({-1,-1});
       vector<int> dr={-1,0,1,0};
       vector<int> dc={0,1,0,-1};
       int t=0;

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(i==-1 && j==-1){
                t++;
                if(!q.empty()) q.push({-1,-1});
                continue;
            }

            
            for(int k=0;k<4;k++){
                int nr=i+dr[k],nc=j+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    fo--;
                }
            }
           
        }

        if(fo==0) return t-1;
        return -1;
    }
};