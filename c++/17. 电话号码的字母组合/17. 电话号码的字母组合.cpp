class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int, string> m;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        vector<string> ans;
        if(digits == "") return ans;
        int num = digits[0] - '0';
        for(int i = 0; i < m[num].size(); i++){
            string tmp;
            tmp.push_back(m[num][i]);
            ans.push_back(tmp);
            
        }
        for(int i = 1; i < digits.size(); i++){
            num = digits[i] - '0';
            vector<string> tmp = ans;
            for(int j = 0; j < ans.size(); j++){
                ans[j].push_back(m[num][0]);
            }
            int n = ans.size();
            for(int k = 1; k < m[num].size(); k++){
                for(int j = 0; j < n; j++){
                    string elem = tmp[j] + m[num][k];
                    ans.push_back(elem);
                }
            }
        }
        return ans;

    }
};