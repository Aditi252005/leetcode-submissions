class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        int n=q.size();
        int m=d.size();

        vector<string> ans;
        for(int i=0;i<n;i++){
            string curr=q[i];
        
            for(int j=0;j<m;j++){
                string s=d[j];
                int dif=0;
                for(int k=0;k<curr.length();k++){
                   if(curr[k]!=s[k]) dif++; 
                   if(dif>2) break;
                } 
                if(dif<=2){
                   ans.push_back(curr); 
                   break;
                } 
            }
            
        }
        return ans;
    }
};