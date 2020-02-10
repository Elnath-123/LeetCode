class Solution {
    public String convert(String s, int numRows) {
        if(s.length() == 0 || s.length() <= numRows || numRows == 1) return s;
        int i = 0;
        String ans = "";
        int k = 1;
        while(i < s.length()){
            ans += s.charAt(i);
            i = k * (2 * numRows - 2);
            k++;
        }
        i = 1;
        
        while(i != numRows - 1){
            k = 1;
            int j = i;
            while(j < s.length()){
                ans += s.charAt(j);
                j = k * (2 * numRows - 2) - i;
                if(j >= s.length()) break;
                ans += s.charAt(j);
                j = j + 2 * i;
                k++;
            }
            i++;
        }
        k = 1;
        while(i < s.length()){
            ans += s.charAt(i);
            i = i + (2 * numRows - 2);
        }
        return ans;
    }
}