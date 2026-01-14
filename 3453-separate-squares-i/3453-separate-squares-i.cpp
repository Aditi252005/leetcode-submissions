class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();
        
        double tota=0.0;
        double lo=INT_MAX;
        double hi=INT_MIN;
        for(int i=0;i<n;i++){
            double s=squares[i][2];
            tota=tota+(s*s);
            lo=min(lo,(double)squares[i][1]);
            hi=max(hi,squares[i][1]+s);
        }

       

        while(hi-lo>1e-6){
            double mid=lo+(hi-lo)/2.0;

            // bottom area till y=mid
            double ba=0.0;
            for(int i=0;i<n;i++){
                if(squares[i][1]>mid) continue;
                double bottom=squares[i][1];
                double top=squares[i][1]+squares[i][2];
                ba=ba+(squares[i][2]*max(0.0,(min(top,mid)-bottom)));
            }  

            if(ba>=tota/2.0){
                hi=mid;
            }
            else{
                lo=mid;
            }
        }
        return hi;
    }
};