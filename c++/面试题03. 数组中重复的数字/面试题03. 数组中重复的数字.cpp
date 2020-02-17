class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = -1;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
            if(m[nums[i]] > 1) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};