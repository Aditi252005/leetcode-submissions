class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int lo=i,hi=m-1;

            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums2[mid]>=nums1[i]){
                    ans=max(ans,mid-i);
                    lo=mid+1;
                }else hi=mid-1;
            }
        }

        return ans;
    }
};