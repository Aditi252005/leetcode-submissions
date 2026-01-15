class Solution {
public:
    int f(vector<int>& v){
        int ans=1;
        int c=1;
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]==1) c++;
            else c=1;
            ans=max(ans,c);
        }
        return ans+1;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int s=min(f(hBars),f(vBars));
        return s*s;
    }
};