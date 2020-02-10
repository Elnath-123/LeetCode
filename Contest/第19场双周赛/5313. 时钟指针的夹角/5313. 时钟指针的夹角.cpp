class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour * 30) % 360 + (minutes * 1.0 / 60 ) * 30;
        double m = minutes * 1.0 / 5 * 30;
        double ans = max(h - m, m - h);
        if(ans > 180){
            ans = 360 - ans;
        }
        return ans;
    }
};