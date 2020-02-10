class Solution {
public
    int ans;
    inline int abs(int n){
        return n  0  -n  n;
    }
    返回最小和
    inline int twoSumClosest(vectorint& nums, int idx, int target){
        int i = idx;
        int j = nums.size() - 1;
        int sum;
        int diff;
        int mindiff = 10000000;
        int minsum = 1000000;
        while(i  j){
            sum = nums[i] + nums[j];
            diff = abs(sum - target);
            if(diff  mindiff){
                mindiff = diff;
                minsum = sum;
            }
            if(nums[i] + nums[j]  target) j--;
            else if(nums[i] + nums[j]  target) i++;
            else{
                i++; 
                j--;
                return sum;    
            }
        }
        return minsum;
    }
    int threeSumClosest(vectorint& nums, int target) {
        ans = 1000000000;
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int minsum = 100000000;
        int mindiff = 100000000;
        for(int i = 0; i  nums.size() - 2; i++){
            int tmpans = twoSumClosest(nums, i + 1, target - nums[i]);
            int sum = nums[i] + tmpans;
            int diff = abs(sum - target);
            if(diff  mindiff){
                mindiff = diff;
                minsum = sum;
            }
        }
        return minsum;
    }
};