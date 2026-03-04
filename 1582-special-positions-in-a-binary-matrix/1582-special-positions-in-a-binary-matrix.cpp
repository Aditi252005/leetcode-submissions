class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        int ans=0;
        vector<int> r(n,0);
        vector<int> c(m,0);
        
        for(int i=0;i<n;i++){
            int k=-1;
            int j=0;
           while(j<m){
                if(mat[i][j]==1){
                    r[i]++;
                    k=j;
                }
                j++;
            }
            if(r[i]==1){ //check
                c[k]=0;
                for(int l=0;l<n;l++){
                    if(mat[l][k]==1) c[k]++;
                }
                if(c[k]==1) ans++;
            }
        }

        return ans;
    }
};