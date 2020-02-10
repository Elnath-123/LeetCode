class Solution {
    Map<String, String> m = new HashMap<>();
    List<String> ans = new ArrayList<>();
    void dfs(String digits, int idx, String tmp, Map<String, String> m, int n){
        if(n == digits.length()){
           
            ans.add(tmp);
            return;
        }
       
            String num = digits.substring(idx, idx + 1);
            
            String str = m.get(num);
            
            for(int j = 0; j < str.length(); j++){
                
                tmp += (str.charAt(j));
                dfs(digits, idx + 1, tmp, m, n + 1);
                tmp = tmp.substring(0, tmp.length() - 1);
            }
       
    }
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) return ans;
        m.put("2", "abc");
        m.put("3", "def");
        m.put("4", "ghi");
        m.put("5", "jkl");
        m.put("6", "mno");
        m.put("7", "pqrs");
        m.put("8", "tuv");
        m.put("9", "wxyz");
        String tmp = "";
        
        dfs(digits, 0, tmp, m, 0);
        return ans;
    }
}