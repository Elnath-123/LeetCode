class Solution {
public:
    
    int countOrders(int n) {
        long long dp[505];
        const int mod = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        dp[2] = 6;
        long long start = 1 + 2 + 3 + 4 + 5;
        long long num = 5;
        for(int i = 3; i <= n; i++){
            dp[i] = (dp[i - 1] * start) % mod;
            num ++;
            start += num;
            num ++;
            start += num;
        }
        return dp[n];
    }
};