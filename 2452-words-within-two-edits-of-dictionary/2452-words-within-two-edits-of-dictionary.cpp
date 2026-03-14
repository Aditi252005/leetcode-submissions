class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        int m=dictionary.size();
        vector<string> ans;

        for(int i=0;i<n;i++){
            string curr=queries[i];
            //edit
            for(int j=0;j<m;j++){
                string d=dictionary[j];
                if(curr.length()!=d.length()) continue;
                int diff=0;
                for(int k=0;k<curr.length();k++){
                    if(curr[k]!=d[k]) diff++;
                    if(diff>2) break;
                }
                if(diff<=2){
                    ans.push_back(curr);
                    break;
                }
            }
            
            
        }
        return ans;
    }
};