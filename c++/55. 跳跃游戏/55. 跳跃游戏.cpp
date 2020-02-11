class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool canjump[50005];
        memset(canjump, false, sizeof(canjump));
        canjump[nums.size() - 1] = true;
        bool ans = true;;
        for(int i = nums.size() - 2; i >= 0; i--){
            for(int j = i + 1; j <= i + nums[i] && j < nums.size(); j++){
                if(canjump[j] == true){
                    canjump[i] = true;
                    break;
                }
            }
        }
        return canjump[0];
    }
};