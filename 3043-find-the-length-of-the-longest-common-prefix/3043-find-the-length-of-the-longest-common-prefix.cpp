class Solution {
public:
    int len(int x){
        int count=0;
        while(x){
            count++;
            x/=10;
        }
        return count;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int m=arr2.size();

        set<int> st;
        for(int i=0;i<n;i++){
            int num=arr1[i];
            while(num){
                st.insert(num);
                num/=10;
            }
        }

        int ans=0;

        for(int i=0;i<m;i++){
            int num=arr2[i];
            while(num){
                if(st.find(num)!=st.end()) ans=max(ans,len(num));
                num/=10;
            }
        }

        return ans;
    }
};