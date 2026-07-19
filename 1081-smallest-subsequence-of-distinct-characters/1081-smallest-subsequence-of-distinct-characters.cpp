class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.length();
        map<char,vector<int>> mp;
        for(int i=0;i<n;i++) mp[s[i]].push_back(i);

        string st;
        string ans(n,'z');
        set<char> se;
        for(int i=0;i<n;i++){
            char ch=s[i];
            vector<int> v;
            if(st.size()) v=mp[st.back()];

            while(!st.empty() && ch<=st.back() && v[v.size()-1]>i && se.find(ch)==se.end()){
                se.erase(st.back());
                st.pop_back();
                if(st.size()) v=mp[st.back()];
            }

            if(se.find(ch)==se.end()) {
                se.insert(ch);
                st.push_back(ch);
            }

            if(st.size()==mp.size()) ans=min(ans,st);
        }

        ans=min(ans,st);
        return ans;

    }
};