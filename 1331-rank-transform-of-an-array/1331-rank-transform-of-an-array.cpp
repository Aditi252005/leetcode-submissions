class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) v[i]={arr[i],i};

        sort(v.begin(),v.end());
        int r=1;
        for(int i=0;i<n;i++) {
            arr[v[i].second]= r;
            r++;
            if(i<n-1 && v[i].first==v[i+1].first) r--;
        }

        return arr;
    }
};