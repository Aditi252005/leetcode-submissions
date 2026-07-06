class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());

        int count=0;
        int a=intervals[0][0];
        int b=intervals[0][1];

        for(int i=1;i<n;i++){
            if(a<=intervals[i][0] && b>=intervals[i][1]) {
                count++;
            }
            else if(intervals[i][0]==a && intervals[i][1]>=b){
                count++;
                b=intervals[i][1];
            }
            else{
                a=intervals[i][0];
                b=intervals[i][1];
            }
        }

       
        return n-count;
    }
};