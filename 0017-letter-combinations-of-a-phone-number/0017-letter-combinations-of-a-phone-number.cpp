class Solution {
public:
    vector<string> s={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void f(int i,string& d,string&v,vector<string>&ans){
        int n=d.length();
        if(i>n-1) {
            ans.push_back(v);
            return;
        }

        for(int j=0;j<s[d[i]-'0'].length();j++){
            v.push_back(s[d[i]-'0'][j]);
            f(i+1,d,v,ans);
            v.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.length();
        
        string v;
        vector<string> ans;
        f(0,digits,v,ans);
        return ans;
    }
};