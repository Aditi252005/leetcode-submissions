class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>& c){
        int n=c.size();
        queue<int> q;
        q.push(i);
        c[i][j]=0;

        while(!q.empty()){
            int b=q.front();
            q.pop();

            for(int k=0;k<n;k++){
                if(c[b][k] && k!=b) {
                    q.push(k);
                    c[b][k]=0;
                    c[k][b]=0;
                }
                if(k==b) c[k][b]=0;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]) {
                    bfs(i,j,isConnected);
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};