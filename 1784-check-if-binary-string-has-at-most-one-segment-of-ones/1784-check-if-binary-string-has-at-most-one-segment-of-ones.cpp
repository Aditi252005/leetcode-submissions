class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        bool check=true;

        for(int i=0;i<n;i++){
            if(s[i]=='0') check=false;
            else if(s[i]=='1' && !check) return false;
        }
        return true;
    }
};