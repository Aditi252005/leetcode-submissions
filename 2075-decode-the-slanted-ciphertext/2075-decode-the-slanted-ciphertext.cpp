class Solution {
public:
    string decodeCiphertext(string e, int rows) {
        int n=e.length();
        int cols=n/rows;
        if(!n) return e;
        vector<vector<char>> s(rows,vector<char>(cols,' '));
        int k=0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                s[i][j]=e[k];
                k++;
            }
        }
        

        string ans;
        
        for(int k=0;k<cols;k++){
            int j=k;
            int i=0;
            while(i<rows && j<cols){
               ans.push_back(s[i][j]); 
               i++;
               j++;
            }
        }
        int a=ans.length()-1;
        while(ans[a]==' ') a--;

        return ans.substr(0,a+1);
    }
};