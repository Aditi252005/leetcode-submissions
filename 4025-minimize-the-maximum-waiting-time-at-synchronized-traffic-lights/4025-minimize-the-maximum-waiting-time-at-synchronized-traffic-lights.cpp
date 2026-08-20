class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& time) {
        int n=time.size();
        for(int i=0;i<n;i++) time[i]=time[i]%period;

        int m=lights.size();
        int maxi=-1;
        for(auto it:lights) maxi=max(maxi,it);

        int ans=0;
        for(int i=0;i<n;i++){
            if(time[i]>=maxi) ans=max(ans,period-time[i]);
        }
        return ans;
    }
};