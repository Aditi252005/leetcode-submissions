class Solution {
public:
    int maxScore(vector<int>& c, int k) {
        int n=c.size();
        int ts=accumulate(c.begin(),c.end(),0);

        int m=n-k;
        int j=0;
        int sum=0;
        while(j<m){sum+=c[j];j++;}

        int i=0;
        int mins=sum;
        while(j<n){
            sum+=c[j];
            sum-=c[i];        
            mins=min(mins,sum);
            i++;
            j++;
        }
        return ts-mins;
    }
};