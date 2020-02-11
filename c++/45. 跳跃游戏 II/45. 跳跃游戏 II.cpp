class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxjump = -1;
        int border;
        int ans = 0;
        maxjump = nums[0];
        border = min(maxjump, n - 1);
        for(int i = 1; i < n; i++){
            maxjump = max(maxjump, i + nums[i]);
            
            if(i == border){
                border = min(maxjump, n - 1);
                ++ans;
            }
        }
        return ans;
    }
};