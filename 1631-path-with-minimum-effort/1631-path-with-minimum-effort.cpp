class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({0,{0,0}});

        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();

            int d=node.first;
            int i=node.second.first;
            int j=node.second.second;

            if(dis[i][j]<d) continue;
            if(i==n-1 && j==m-1) return d;

            for(int k=0;k<4;k++){
                int ni=i+dr[k];
                int nj=j+dc[k];

                if(ni>=0 && nj>=0 && ni<n && nj<m){
                    int c= max(d,abs(h[i][j]-h[ni][nj]));
                    if(dis[ni][nj]>c){
                        dis[ni][nj]=c;
                        pq.push({c,{ni,nj}});
                    }
                }
            }
        }
        return 0;
    }
};