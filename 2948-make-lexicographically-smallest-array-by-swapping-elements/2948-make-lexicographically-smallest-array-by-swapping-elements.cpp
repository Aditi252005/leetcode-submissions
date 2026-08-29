class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());

        unordered_map<int,vector<int>> mp;
        unordered_map<int,int> p;
        unordered_map<int,int> itr;
        int grp=1;

        for(int i=0;i<n;i++){
            if(i==0) mp[grp].push_back(temp[i]);
            else if(temp[i]-temp[i-1]<=limit) mp[grp].push_back(temp[i]);
            else{
                grp++;
                mp[grp].push_back(temp[i]);
            }
            p[temp[i]]=grp;
            itr[grp]=0;
        }


        for(int i=0;i<n;i++){
            int group= p[nums[i]];
            int k= itr[group];

            nums[i]= mp[group][k];
            itr[group]++;
        }

        return nums;
    }
};