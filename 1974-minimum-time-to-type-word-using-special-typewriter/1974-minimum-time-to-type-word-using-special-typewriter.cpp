class Solution {
public:
    int minTimeToType(string word) {
        int n=word.length();
        int ans=0;
        int prev=0;

        for(int i=0;i<n;i++){
            int curr=word[i]-'a';
            int d=abs(curr-prev);
            ans=ans+min(d,26-d)+1;
            prev=curr;
           
        }
        return ans;
    }
};