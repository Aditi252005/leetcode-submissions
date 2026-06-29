class Solution {
public:
    int numOfStrings(vector<string>& p, string s) {
        int m=p.size();
        int n=s.length();
        map<string,int> mp;
        for(auto w:p) mp[w]++;

        int ans=0;
        for(int i=0;i<n;i++){
            string v;
            for(int j=i;j<n;j++){
                v.push_back(s[j]);
                if(mp.find(v)!=mp.end()) {ans+=mp[v];mp.erase(v);}
            }
        }
        return ans;
    }
};