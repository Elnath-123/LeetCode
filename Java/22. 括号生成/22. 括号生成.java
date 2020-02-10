class Solution {
    List<String> ans = new ArrayList<>();
    public void recursion(String parenthesis, int left, int right, int cnt, int n){
        if(cnt == 2 * n){
            ans.add(parenthesis);
            return;
        }
        if(left < n)
            recursion(parenthesis + "(", left + 1, right, cnt + 1, n);
        if(left > right){
            recursion(parenthesis + ")", left, right + 1, cnt + 1, n);
        }
    }
    public List<String> generateParenthesis(int n) {
        recursion("", 0, 0, 0, n);
        return ans;
    }
    
}