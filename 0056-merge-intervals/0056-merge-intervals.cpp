class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intv) {
        int n=intv.size();

        vector<vector<int>> ans;
        sort(intv.begin(),intv.end());

        for(int i=0;i<n;i++){
            while(ans.size() && intv[i][0]<=ans.back()[1]){
                intv[i][0]=min(ans.back()[0],intv[i][0]);
                intv[i][1]=max(ans.back()[1],intv[i][1]);
                ans.pop_back();
            }
            ans.push_back({intv[i][0],intv[i][1]});
        }
        return ans;
    }
};