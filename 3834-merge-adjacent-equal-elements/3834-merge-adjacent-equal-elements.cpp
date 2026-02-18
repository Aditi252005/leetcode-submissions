class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        vector<long long> a;
        //a.push_back(nums[0]);
        
        int j=0;
        while(j<n){
            a.push_back(nums[j]);  //2 2
            int m=a.size();  //2
            if(m>1){
                long long  b=a[m-1];  //2
                long long c=a[m-2];  //2
                while(m>1 && b==c){
                    a.pop_back();
                    a.pop_back();
                    a.push_back(2*b); //4
                    m--; //1
                    if(m<=1) break;
                    b=a[m-1];
                    c=a[m-2];  
                }
            }
            j++;
        }
        return a;
    }
};