class Solution {
public:
    void swap(int &a, int &b){
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return;
        int i = nums.size() - 1;
        int j = nums.size() - 2;
        while(i >= 0 && j >= 0 && nums[j] >= nums[i]){
            i--,j--;
        }
        if(j >= 0 && nums[j] <= nums[i]){
            int k = nums.size() - 1;
            while(nums[j] >= nums[k] && j < k) k--;
            swap(nums[j], nums[k]);
            sort(nums.begin() + i, nums.end());
        }
        else{
            sort(nums.begin(), nums.end());
        }
    }
};