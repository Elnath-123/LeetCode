class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int t = sqrt(2 * N);
        int cnt = 0;
        for(int a = 1; a <= t; a++){
            //if( 2 * N % a == 0 && a > 2 * N / a) cnt++; 
            if(2 * N % a == 0)
                if((2 * N / a - a + 1) % 2 == 0){
                    int x = (2 * N / a - a + 1) / 2;
                    if(x >= 1) cnt++;
                }
        }
        return cnt;
    }
};