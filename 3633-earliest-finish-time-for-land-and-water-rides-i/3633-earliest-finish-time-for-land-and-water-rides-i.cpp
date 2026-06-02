class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX;
        //aditixx25

        for(int i=0;i<landStartTime.size();i++){
            for(int j=0;j<waterStartTime.size();j++){
                int ls=landStartTime[i];
                int le=ls+landDuration[i];
                int ws=max(waterStartTime[j],le);
                int we=ws+waterDuration[j];
                ans=min(ans,we);


                int wfs = waterStartTime[j];
                int wfe = wfs + waterDuration[j];
                int lss = max(landStartTime[i], wfe);
                int lse = lss + landDuration[i];
                ans = min(ans,lse);
            }
        }
        return ans;  
    }
};