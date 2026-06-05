class Solution {
public:
    bool valid(int i,int j,int n,vector<string>&v){
        
        for(int a=0;a<i;a++) if(v[a][j]=='Q') return false;

        for(int a=i-1,b=j-1;a>=0 && b>=0;a--,b--) if(v[a][b]=='Q') return false;

        for(int a=i-1,b=j+1;a>=0 && b<n;a--,b++) if(v[a][b]=='Q') return false;


        return true;
    }
    void f(int i,int placed,int n,vector<string>& v,vector<vector<string>>& ans){
        //if(i>n-1) return;
        if(placed==n){
            ans.push_back(v);
            return;
        }

        for(int k=0;k<n;k++){
            if(valid(i,k,n,v)){
                v[i][k]='Q';
                f(i+1,placed+1,n,v,ans);
                v[i][k]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n,string(n,'.'));

        f(0,0,n,v,ans);
        return ans;
    }
};