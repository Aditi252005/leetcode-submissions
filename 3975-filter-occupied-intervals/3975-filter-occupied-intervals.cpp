class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& it, int fs, int fe) {
        int n=it.size();

        sort(it.begin(),it.end());
        vector<vector<int>> merge;
        
        for(int i=0;i<n;i++){
            int a=it[i][0];
            int b=it[i][1];
            int m=merge.size();

            if(merge.empty() || merge[m-1][1]<a-1) merge.push_back({a,b});
            else {
                merge[m-1][0]=min(merge[m-1][0],a);
                merge[m-1][1]=max(merge[m-1][1],b);
            }
        }
        
        for(int i=0;i<merge.size();i++){
            int a=merge[i][0];
            int b=merge[i][1];

            if(a >= fs && b <= fe){
               merge.erase(merge.begin() + i);
               i--;
               continue;
            }

            else if(a<fs && fe<b){
                merge[i][1]=fs-1;
                merge.push_back({fe+1,b});
            }

            else if(a<fs && fs<=b) {
                merge[i][1]=fs-1;
            }
            else if(a<=fe && fe<b){
                merge[i][0]=fe+1;
            }
        }

        sort(merge.begin(),merge.end());
        return merge;
    }
};