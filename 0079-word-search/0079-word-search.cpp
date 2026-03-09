class Solution {
public:
    bool f(int i,int j,vector<vector<char>>&b,string&s,int k,vector<vector<int>>&vis){
        int n=b.size();
        int m=b[0].size();
        if(i<0 || j<0 || i>n-1 || j>m-1 || vis[i][j]) return false;
        if(k==s.length()-1){
            if(b[i][j]==s[k]) return true;
            return false;
        } 
        
        vis[i][j]=1;
        bool ans=false;
        if(b[i][j]==s[k]){
            ans= f(i+1,j,b,s,k+1,vis) || f(i,j+1,b,s,k+1,vis) || f(i-1,j,b,s,k+1,vis) || f(i,j-1,b,s,k+1,vis);

        }
        vis[i][j]=0;
        //cout<<i<<j<<ans<<endl;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                   if(f(i,j,board,word,0,vis)) return true;
                }
            }
        }
        return false;
        //a b
        //c d
    }
};