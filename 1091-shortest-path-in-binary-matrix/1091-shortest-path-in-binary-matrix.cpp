class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        if(!grid[0][0]) q.push({0,0});
        int dr[8]={-1,-1,-1,0,1,1,1,0};
        int dc[8]={-1,0,1,1,1,0,-1,-1};
        int d=1;

        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto [i,j]=q.front();
                q.pop();

                if(i==n-1 && j==m-1) return d;

                for(int k=0;k<8;k++){
                    int ni=i+dr[k];
                    int nj=j+dc[k];

                    if(ni>=0 && nj>=0 && ni<n && nj<n && !grid[ni][nj]){
                        grid[ni][nj]=1;
                        q.push({ni,nj});
                    }
                }
            }
            d++;
        }
        return -1;
    }
};