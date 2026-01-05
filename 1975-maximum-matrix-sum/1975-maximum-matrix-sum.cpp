class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        long long sum=0;
        int mine=INT_MAX;
        int neg=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0) neg++;
                sum+=abs(matrix[i][j]);
                mine=min(mine,abs(matrix[i][j]));
                
            }
        }
        
       
        if(neg%2==1){
            sum=sum-2*mine;
        }

        return sum;
        
    }
};