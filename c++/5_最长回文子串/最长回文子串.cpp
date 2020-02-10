class Solution {
public:
    int maxlen = 1;
    string centerExpand(string s, int pos){
        bool satisfied = true;
        int i, j;
        i = j = pos;

        while( i >= 0 && j < s.size() && (s[i] == s[j]) ) {
            i--;
            j++;
        }
        i++, j--;
        s = s.substr(i, j - i + 1);
        string str;
        for(char ch : s){
            if(ch != '#') str.push_back(ch);
        }
        return str;
    }
    string longestPalindrome(string s) {
        string str;
        char pad_ch = '#';
        for(int i = 0; i < s.size(); i++){
            str.push_back(s[i]);
            if(i != s.size() - 1) str.push_back('#'); 
        }
        string ans;
        
        for(int i = 0; i < str.size(); i++){
            string curans = centerExpand(str, i);
            if( curans.size() >= maxlen ){
                ans = curans;
                maxlen = curans.size();
            }
        }

        return ans;

        
    }
};