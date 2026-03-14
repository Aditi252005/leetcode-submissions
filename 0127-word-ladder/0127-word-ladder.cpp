class Solution {
public:
    int ladderLength(string b, string e, vector<string>& wordList) {
        int n=wordList.size();
        set<string> st(wordList.begin(),wordList.end());
        set<string> vis;
        queue<pair<string,int>> q;
        q.push({b,1});
       

        while(!q.empty()){
            string curr=q.front().first;
            int steps=q.front().second;
            q.pop();

            if(vis.count(curr)) continue;
            vis.insert(curr);
            if(curr==e) return steps;
            

            string temp=curr;
            for(int j=0;j<temp.length();j++){
                for(int i=0;i<26;i++){
                    temp[j]='a'+i;
                    if(st.find(temp)!=st.end()) q.push({temp,steps+1});
                    
                }
                temp=curr;
            }
           
        }
        return 0;
    }
};