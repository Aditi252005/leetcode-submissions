class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        
        int lo=*max_element(weights.begin(),weights.end());
        int hi=accumulate(weights.begin(),weights.end(),0);

        while(lo<hi){
            int mid= lo+(hi-lo)/2;
            int d=1;
            int s=0;
            bool check=false;

            for(int i=0;i<n;i++){
                if(s+weights[i]<=mid) s+=weights[i];
                else {s=weights[i];d++;}
                if(d>days){
                    break;
                }
            }
            if(d<=days) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};