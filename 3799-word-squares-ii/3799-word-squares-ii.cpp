class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        
        int n=words.size();
        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            char a=words[i][0];//a
            char b=words[i][words[i].length()-1];//e
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(words[j][0]==a){
                        char c=words[j][words[j].length()-1];//a
                        for(int k=0;k<n;k++){
                            if(i!=k && j!=k){
                                if(words[k][0]==b){
                                    char d=words[k][words[k].length()-1];//o
                                    for(int l=0;l<n;l++){
                                        if(i!=l && j!=l && k!=l){
                                            if(words[l][0]==c && words[l][words[l].length()-1]==d) ans.push_back({words[i],words[j],words[k],words[l]});
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};