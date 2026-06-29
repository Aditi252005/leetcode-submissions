class Solution {
public:
    int numOfStrings(vector<string>& p, string s) {
        int m=p.size();
        int n=s.length();
        
        int ans=0;
        for(int i=0;i<m;i++){
            string v=p[i];
            if(s.find(v)!=string::npos) {ans++;}
        } 
        return ans;
    }
};