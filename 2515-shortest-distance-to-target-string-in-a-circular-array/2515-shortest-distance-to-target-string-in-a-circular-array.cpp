class Solution {
public:
    int closestTarget(vector<string>& words, string t, int idx) {
        int n=words.size();
        int ans=INT_MAX;
        int c=(idx+1)%n;

        int i=idx,j=(idx+1)%n;
        int a=0,b=1;

        while(i!=c){ 
            if(words[i]==t) ans=min(ans,a);
            if(words[j]==t) ans=min(ans,b);

            i=(i-1+n)%n;
            j=(j+1)%n;
            a++;
            b++;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};