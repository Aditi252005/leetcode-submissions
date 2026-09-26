class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        int n=s.length();
        unordered_map<string,string> mp;
        for(auto a:k) mp[a[0]]=a[1];
 
        string temp;
        string ans;
        bool found=false;
        for(int i=0;i<n;i++){
            if(s[i]=='(') found=true;
            else if(s[i]==')') {
                if(mp.find(temp)==mp.end()) ans.push_back('?');
                else for(auto ch:mp[temp]) ans.push_back(ch);
                found=false;
                temp="";
            }
            else if(found) temp.push_back(s[i]);
            else ans.push_back(s[i]);
        }
        return ans;
    }
};