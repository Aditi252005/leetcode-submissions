class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        
        long long ods= (long long) n*n;
        long long evs= (long long) n*n +n;

        return gcd(ods,evs);
    }
};