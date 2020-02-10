class Solution {
    struct Node{
        int idx;
        int val;
    };
public:
    /* dp[i]从第i个位置开始跳最多访问的下标 */
    /* dp[i] = max(dp[j]) + 1, j ∈[i - d, i + d]; */
    static bool cmp(Node a, Node b){
        return a.val < b.val;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        if(n == 0) return 0;
        int dp[n];
        Node node[n];
        for(int i = 0; i < n; i++) dp[i] = 1;
        for(int i = 0; i < n; i++){
            node[i].idx = i;
            node[i].val = arr[i];
        }
        sort(node, node + n, cmp);
        for(int i = 0; i < n; i++){
            int idx = node[i].idx;
            for(int j = idx - 1; j >= 0 && j >= idx - d; j--){
                if(arr[j] < arr[idx]) dp[idx] = max(dp[idx], dp[j] + 1); 
                else break;
            } 
            for(int j = idx + 1; j < n && j <= idx + d; j++){
                if(arr[j] < arr[idx]) dp[idx] = max(dp[idx], dp[j] + 1);
                else break;
            }            
        }
        return *max_element(dp, dp + n);

    }
};