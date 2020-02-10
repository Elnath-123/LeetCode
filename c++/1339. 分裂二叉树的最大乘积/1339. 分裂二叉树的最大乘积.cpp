/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    long long sum;
    long long ans;
    void dfs_sum(TreeNode *root){
        if(root == NULL) return;
        sum += root->val;
        dfs_sum(root->left);
        dfs_sum(root->right);
    }
    long long postOrder(TreeNode* root){
        if(root == NULL) return 0;
        long long sub_sum;
        sub_sum += root->val;
        sub_sum += postOrder(root->left);
        sub_sum += postOrder(root->right);
        if(sub_sum * (sum - sub_sum) > ans){
            ans = sub_sum * (sum - sub_sum);
        }
        return sub_sum;
    }
    int maxProduct(TreeNode* root) {
        sum = ans = 0;
        dfs_sum(root);
        postOrder(root);
        return ans % (long long)(1e9 + 7);
    }
};