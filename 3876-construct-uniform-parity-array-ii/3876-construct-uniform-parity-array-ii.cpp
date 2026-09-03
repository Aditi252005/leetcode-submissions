class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int mine=INT_MAX,mino=INT_MAX;
        int odd=0,even=0;

        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                even++;
                mine=min(mine,nums1[i]);
            }else{
                odd++;
                mino=min(mino,nums1[i]);
            }
        }

        if(even==n || odd==n || mine>=mino+1) return true;
        return false;
    }
};