class Solution {
public:
    int minCost(vector<int>& s, vector<int>& h, vector<int>& r, vector<int>& c) {
        int n=r.size();
        int m=c.size();
        int x=h[0];
        int y=h[1]; 
        int i=s[0];
        int j=s[1];
        int ans=0;

        if(i<x) {
            for(int k=i+1;k<=x;k++) ans+=r[k];
        }else{
            for(int k=i-1;k>=x;k--) ans+=r[k];
        }

        if(j<y) {
            for(int k=j+1;k<=y;k++) ans+=c[k];
        }else{
            for(int k=j-1;k>=y;k--) ans+=c[k];
        }

        return ans;

        
        // priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        // pq.push({0,{s[0],s[1]}});

        // vector<vector<int>> dis(n,vector<int> (m,INT_MAX));
        // dis[s[0]][s[1]]=0;

        // int dr[4]={-1,0,1,0};
        // int dc[4]={0,1,0,-1};

        // while(!pq.empty()){
        //     auto node=pq.top();
        //     pq.pop();
        //     int d=node.first;
        //     int i=node.second.first;
        //     int j=node.second.second;
           
        //     if(d>dis[i][j]) continue;
        //     if(i==x && j==y) return d;

        //     for(int k=0;k<4;k++){
        //         int ni=i+dr[k];
        //         int nj=j+dc[k];

        //         if(ni>=0 && nj>=0 && ni<n && nj<m){
        //             int c1=ni!=i?r[ni]:0;
        //             int c2=nj!=j?c[nj]:0;

        //             if(dis[ni][nj]>d+c1+c2){
        //                 dis[ni][nj]=d+c1+c2;
        //                 pq.push({dis[ni][nj],{ni,nj}});
        //             }
        //         }
        //     }
        // }
        // return 0;

    }
};