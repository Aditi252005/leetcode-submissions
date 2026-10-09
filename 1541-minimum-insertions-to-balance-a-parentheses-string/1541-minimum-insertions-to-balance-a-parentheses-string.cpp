class Solution {
public:
    int minInsertions(string s) {
        int n=s.length();

        int ans=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                if(count%2==1){
                    ans++;
                    count++;
                }
                else count+=2;
            }
            else if(count==0) {ans++;count++;}
            else count--;
        }
        
        return ans+count;
    }
};