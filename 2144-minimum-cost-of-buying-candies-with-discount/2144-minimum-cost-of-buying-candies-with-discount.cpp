class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n=cost.size();
        if(n==1) return cost[0];
        if(n==2) return cost[0]+cost[1];
        int tcost=0;
        sort(cost.begin(),cost.end());
        int i=n-1;
        int j=n%3;
        while(i>j){
            tcost=tcost+cost[i]+cost[i-1];
            i=i-3;
        }
        for(int i=0;i<j;i++) tcost=tcost+cost[i];
        return tcost;
    }
};