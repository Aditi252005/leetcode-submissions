class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n=words.size();
        string ans;

        for(int i=0;i<n;i++){
            int s=0;
            int m=words[i].length();
            for(int j=0;j<m;j++){
                char ch=words[i][j];
                s+=weights[ch-'a'];
            }
            s=s%26;
            ans+='a'+(26-s)-1;
        }
        return ans;
    }
};