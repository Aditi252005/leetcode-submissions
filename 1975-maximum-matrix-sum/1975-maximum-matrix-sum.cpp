class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> s;
        long long sum=0;
        int mine=INT_MAX;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0) s.push_back(-matrix[i][j]);
                else{
                    sum+=matrix[i][j];
                    mine=min(mine,matrix[i][j]);
                }
            }
        }
        
        sort(s.begin(),s.end());
        if(s.size()%2==1){
            if(s[0]>mine) sum=sum-2*mine+accumulate(s.begin(),s.end(),0LL);
            else sum=sum+accumulate(s.begin()+1,s.end(),0LL)-s[0];
        }else{
            sum=sum+accumulate(s.begin(),s.end(),0LL);
        }

        return sum;
        
    }
};