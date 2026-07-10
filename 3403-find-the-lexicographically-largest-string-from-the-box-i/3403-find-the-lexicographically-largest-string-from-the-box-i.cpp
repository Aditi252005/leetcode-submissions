class Solution {
public:
    string answerString(string word, int num) {
        int n=word.length();
        if(num==1) return word;

        string ans="";
        int l=n-num+1;
        for(int i=0;i<n;i++){
            string temp= word.substr(i,l);
            ans=max(ans,temp);
        }
        
        return ans;
    }
};