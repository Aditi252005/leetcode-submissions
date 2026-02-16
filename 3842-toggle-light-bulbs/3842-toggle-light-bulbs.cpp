class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n=bulbs.size();
       // sort(bulbs.begin(),bulbs.end());

        map<int,int> mp;
        for(auto it:bulbs){
            mp[it]++;
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.second%2==1) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};