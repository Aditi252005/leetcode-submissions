class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.length();

        int count=0;
        vector<int> v(26,-1);
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z'){
                if(v[word[i]-'a']==-1) v[word[i]-'a']=0;
                else if(v[word[i]-'a']==1) {count++;v[word[i]-'a']=2;}
            }
            else{
                if(v[word[i]-'A']==-1) v[word[i]-'A']=1;
                else if(v[word[i]-'A']==0) {count++;v[word[i]-'A']=2;}
            }
        }
        return count;
    }
};