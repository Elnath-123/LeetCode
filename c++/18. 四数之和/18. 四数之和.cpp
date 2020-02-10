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

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        if(nums.size() == 0) return ans;
        for(int i = 0; i < nums.size(); i++){
            int j;
            for(j = i + 1; j < nums.size(); j++){
                vector<vector<int>> temp = twoSum(nums, j + 1, target - nums[i] - nums[j]);
                for(int k = 0; k < temp.size(); k++){
                    temp[k].push_back(nums[i]);
                    temp[k].push_back(nums[j]);
                }
                for(int k = 0; k < temp.size(); k++){
                    ans.push_back(temp[k]);
                }
                while(j < nums.size() - 1 && nums[j] == nums[j + 1]) j++;
            }
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
        } 
        return ans;
    }
    
};