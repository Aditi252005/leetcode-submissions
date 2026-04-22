class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        int n=q.size();
        int m=d.size();
        set<string> st(d.begin(),d.end());

        vector<string> ans;
        for(int i=0;i<n;i++){
            string curr=q[i];
            if(st.find(curr)!=st.end()) ans.push_back(curr);
            else{
                for(int j=0;j<m;j++){
                    string s=d[j];
                    int dif=0;
                    for(int k=0;k<curr.length();k++) if(curr[k]!=s[k]) dif++;
                    if(dif<=2  && (ans.size()==0 || ans[ans.size()-1]!=curr)) ans.push_back(curr);
                }
            }
        }
        return ans;
    }
};