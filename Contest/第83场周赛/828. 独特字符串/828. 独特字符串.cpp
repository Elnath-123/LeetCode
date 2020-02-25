class Solution {
public:
    int uniqueLetterString(string s) {
        const int mod = 1e9 + 7;
        unordered_map<char, vector<int>> m;
        for(int i = 0; i < s.size(); i++){
            m[s[i]].push_back(i);
        }
        int cnt = 0;
        for(auto it = m.begin(); it != m.end(); it++){
            vector<int> vec = it->second;
            int start = -1;
            int j = 0;
            while(j < vec.size() - 1){
                cnt += (vec[j] - start) * (vec[j + 1] - vec[j]);
                start = vec[j];
                j++;
            }
            cnt += (vec[j] - start) * (s.size() - vec[j]);
        }
        return cnt % mod;
    }
};