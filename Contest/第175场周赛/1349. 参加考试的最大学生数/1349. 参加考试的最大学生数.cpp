class Solution {
public:
    /* dp[i][state] 表示 前i行，座位坐人状态为state时，无法作弊的最大学生人数*/
    /* dp[i][state] = max(dp[i][state], dp[i - 1][pre_state] + bitcount(state)) */
    int dp[9][1 << 8];
    int lowbit(int x){
        return x & -x;
    }
    int bitcount(int x){
        int cnt = 0;
        while(x > 0){
            cnt++;
            x -= lowbit(x);
        }
        return cnt;
    }
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        //将第0行空出来，将index为1的看作第一行。 由于seats是下标为0开始的，因此seats[i - 1][?]就是本行
        //由于dp是从下标为1开始的，因此dp[i - 1][?]是上一行
        for(int i = 1; i <= m; i++){
            for(int state = 0; state < (1 << n); state++){
                for(int pre_state = 0; pre_state < (1 << n); pre_state++){
                    if(dp[i - 1][pre_state] == -1) continue;
                    bool valid = true;
                    for(int j = 0; j < n; j++){
                        if(((state >> j) & 1) == 0) continue;
                       /* if(seats[i - 1][j] == '#') valid = false;
                        if(j + 1 < n && ((state >> (n - j - 1)) & 1)) valid = false; //右移j+1位，判断当前位的右方是否有人坐
                        if(j - 1 >= 0 && ((state >> (n - j + 1)) & 1)) valid = false; //右移j-1位，判断当前位的左方是否有人坐
                        if(j + 1 < n && ((pre_state >> (n - j - 1)) & 1)) valid = false; //右移j+1位，判断右上方是否有人坐
                        if(j - 1 >= 0 && ((pre_state >> (n - j + 1)) & 1)) valid = false; //右移j-1位，判断左上方是否有人坐*/
                        if(((state >> j) & 1) == 0) continue;
                        if(seats[i - 1][j] == '#') valid = false;
                        if(j + 1 < n && ((state >> (j + 1)) & 1)) valid = false; //右移j+1位，判断当前位的右方是否有人坐
                        if(j - 1 >= 0 && ((state >> (j - 1)) & 1)) valid = false; //右移j-1位，判断当前位的左方是否有人坐
                        if(j + 1 < n && ((pre_state >> (j + 1)) & 1)) valid = false; //右移j+1位，判断右上方是否有人坐
                        if(j - 1 >= 0 && ((pre_state >> (j - 1)) & 1)) valid = false; //右移j-1位，判断左上方是否有人坐
                    }
                    if(valid == false) continue;
                    dp[i][state] = max(dp[i][state], dp[i - 1][pre_state] + bitcount(state));            
                }
            }
        }
        int maxv = -1;
        for(int i = 0; i < (1 << n); i++){
           // cout << dp[m][i] << ' ';
            maxv = max(maxv, dp[m][i]);
        }
        return maxv;
    }
};