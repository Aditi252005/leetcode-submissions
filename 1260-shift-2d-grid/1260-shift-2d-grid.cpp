class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) v.push_back(grid[i][j]);
        }

        k=k%v.size();
        
        int i=v.size()-1;
        vector<int> c;
        while(k){
            c.push_back(v[i]);
            i--;
            k--;
        }
        reverse(c.begin(),c.end());

        int j=v.size()-1;
        while(i>=0){
            v[j]=v[i];
            i--;
            j--;
        }
        i=c.size()-1;
        while(i>=0){
            v[j]=c[i];
            i--;
            j--;
        }

        int l=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {grid[i][j]=v[l];l++;}
        }

        return grid;
    }
};