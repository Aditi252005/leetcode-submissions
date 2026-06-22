class Solution {
public:
    int ladderLength(string b, string e, vector<string>& w) {
        int n=b.length();
        int m=w.size();
        set<string> st(w.begin(),w.end());
        if(st.find(e)==st.end()) return 0;

        queue<pair<string,int>> q;
        q.push({b,1});

        while(!q.empty()){
            auto[s,steps]=q.front();
            q.pop();

            if(s==e) return steps;
           
            for(int i=0;i<s.size();i++){
                char orig = s[i];

                for(char ch='a'; ch<='z'; ch++){
                    s[i] = ch;

                    if(st.count(s)){
                        q.push({s,steps+1});
                        st.erase(s);   
                    }
                }

                s[i] = orig;
            }
        }
        return 0;
    }
};