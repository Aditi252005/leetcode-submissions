class Solution {
public:
    int minSwaps(string s) {
        int n=s.length();
        int count=0;

        int i=0;
        int j=n-1;
        int bal=0;

        while(i<j){
            if(s[i]=='[') bal++;
            else bal--;

            if(bal<0){
                while(i<j && s[j]==']')j--;
                swap(s[i],s[j]);
                count++;
                bal=1;
            }
            i++;
        }
        return count;
    }
};