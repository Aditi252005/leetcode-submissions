class Solution {
public:
    string clearStars(string s) {
        int n=s.length();
        reverse(s.begin(),s.end());

        priority_queue<pair<char,int>, vector<pair<char,int>>, greater<>> pq;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='*'){
                s[i]='#';
                if(!pq.size()) continue;

                auto [ch,idx]=pq.top();
                pq.pop();

                s[idx]='#';
            }
            else pq.push({s[i],i});
        }

        string ans;
        for(int i=0;i<n;i++){
            if(s[i]!='#') ans.push_back(s[i]);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};