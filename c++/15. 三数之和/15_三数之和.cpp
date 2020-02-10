class Solution {
public:
    vector<vector<int>> twoSum(vector<int> nums, int idx, int sum){
        vector<vector<int>> ans;
        int i = idx;
        int j = nums.size() - 1;
        while(i < j){
            if(nums[i] + nums[j] > sum) j--;
            else if(nums[i] + nums[j] < sum)i++;
            else {
                vector<int> tmp;
                tmp.push_back(nums[i]);
                tmp.push_back(nums[j]);
                ans.push_back(tmp);
                while(j > 0 && nums[j] == nums[j - 1]) j--;
                while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
                i++, j--;
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> threeans;
        if(nums.size() == 0) return threeans;
        for(int i = 0; i < nums.size() - 1; i++){
            
            vector<vector<int>> twoans = twoSum(nums, i + 1, 0 - nums[i]);
            
            for(int j = 0; j < twoans.size(); j++){
                twoans[j].push_back(nums[i]);
            }
            for(int j = 0; j < twoans.size(); j++){
                threeans.push_back(twoans[j]);
            }
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        }
        return threeans;
    }
};