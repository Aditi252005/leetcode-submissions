class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();

        map<char,int> smp,tmp;
        for(auto ch:t) {tmp[ch]++;}

        int j=0;
        int i=0;
        int ans=INT_MAX;
        int start;
        while(j<n){
            char ch=s[j];
            if(tmp.find(ch)!=tmp.end()) smp[ch]++;

            bool valid = true;
            for(auto p : tmp){
                if(smp[p.first] < p.second){
                    valid = false;
                    break;
                }
            }
            if(valid){   
                while(i<j){
                    if(tmp.find(s[i])==tmp.end()) i++;
                    else if(smp[s[i]]>tmp[s[i]]) {
                        smp[s[i]]--;
                        i++;
                    }
                    else break;
                }
                if(j-i+1<ans){
                    ans=j-i+1;
                    start=i;
                }
                ans=min(ans,j-i+1);
            }

            j++;
        }
        if(ans==INT_MAX) return "";
        return s.substr(start,ans);
        

    }
};