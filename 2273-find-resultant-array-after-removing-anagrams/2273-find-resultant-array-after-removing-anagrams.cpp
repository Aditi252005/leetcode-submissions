class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<string> ans;
        vector<string> st;

        for(auto word:words){
            string s=word;
            sort(s.begin(),s.end());
            if(st.size() && st[st.size()-1]==s) continue;
            st.push_back(s);
            ans.push_back(word);
        }
        return ans;
    }
};