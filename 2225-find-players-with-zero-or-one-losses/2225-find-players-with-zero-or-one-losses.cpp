class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        map<int,int> lose;
        set<int> win;

        for(auto it:matches){
            win.insert(it[0]);
            lose[it[1]]++;
        }

        vector<vector<int>> ans(2);

        for(auto w:win){
            if(lose.find(w)==lose.end()) ans[0].push_back(w);
        }
        for(auto l:lose){
            if(l.second==1) ans[1].push_back(l.first);
        }

        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());

        return ans;
    }
};