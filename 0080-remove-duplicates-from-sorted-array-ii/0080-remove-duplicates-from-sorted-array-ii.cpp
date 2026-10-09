class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();

        int i=-1;
        int j=1;
        int count=1;
        while(j<n){
            if(nums[j]==nums[j-1]){ 
                count++;
                if(count>2) {
                    if(i==-1) i=j;
                    while(j<n && nums[j]==nums[j-1]) j++;
                    count=1;
                }
            }
            else count=1;
            if(i!=-1 && j<n) {cout<<i<<j<<endl;nums[i]=nums[j];i++;}
            j++;
        }
        return i==-1?n:i;
    }
};