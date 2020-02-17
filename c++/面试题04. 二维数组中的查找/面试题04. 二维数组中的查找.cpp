class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        int stdd = matrix[0][n - 1];
        int row = 0, col = n - 1;
        bool ans = false;
        while(row >= 0 && row < m && col >= 0 && col < n){
            if(target > stdd && row + 1 < m) stdd = matrix[++row][col];
            else if(target < stdd && col - 1 >= 0) stdd = matrix[row][--col];
            else if(target == stdd){ans = true; break;}
            else break;
        }
        return ans;
    }
};