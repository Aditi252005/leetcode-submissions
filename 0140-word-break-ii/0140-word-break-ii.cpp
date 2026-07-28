class Solution {
public:
    void f(int i,string&v,string&s,set<string>dic,vector<string>&ans){
        int n=s.length();
        if(i==n){
            v.pop_back();
            ans.push_back(v);
            return;
        }

        string temp;
       
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(dic.find(temp)!=dic.end()){
                temp+=' ';
                string a=v+temp;
                f(j+1,a,s,dic,ans);
                temp.pop_back(); //removing space
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& word) {
        int n=s.length();
        int m=word.size();

        set<string> dic(word.begin(),word.end());
       
        vector<string> ans;
        string v;
        f(0,v,s,dic,ans);
        return ans;
    }
};