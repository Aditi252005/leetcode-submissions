class Solution {
public:
    bool canTake(string &prev, string &curr) {
        if (curr.size() != prev.size() + 1) return false;

        int i = 0, j = 0;
        bool skipped = false;

        while (i < prev.size() && j < curr.size()) {
            if (prev[i] == curr[j]) {
                i++;
                j++;
            } else {
                if (skipped) return false;
                skipped = true;
                j++;
            }
        }

        return true;
    }
    int f(int i,int j,vector<pair<int,string>>& v,vector<vector<int>>&dp){
        int n=v.size();
        if(j==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int take=0;
        if (i == 0 ||
            (v[j].first == v[i].first + 1 &&
             canTake(v[i].second, v[j].second))) {

            take = 1 + f(j,j + 1, v, dp);
        }
        

        int skip= f(i,j+1,v,dp);
        return dp[i][j]=max(take,skip);

    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<pair<int,string>> v;
        for(auto w:words){
            v.push_back({w.length(),w});
        }
        v.push_back({0,""});
        sort(v.begin(),v.end());

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return f(0,1,v,dp);

    }
};