class Solution {
public:
    const long long mod = 1e9 + 7;
    int fib(int n) {
        long long g = 1;
        long long f = 1;
        if(n == 1 || n == 2) return 1;
        if(n == 0) return 0;

        while(n > 2){
            g = (g + f);
            f = (g - f);
            g = g % mod;
            f = f % mod;
            n--;
        }
        return g;
    }
};