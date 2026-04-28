class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<int> v;
        int st=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
                if(abs(grid[i][j]-st)%x!=0) return -1;
            }
        }

        sort(v.begin(),v.end());
        int mid=v.size()/2;
        int op=0;

        for(int i=0;i<v.size();i++){
            op+=(abs(v[mid]-v[i]))/x;
        }
        return op;
    }
};