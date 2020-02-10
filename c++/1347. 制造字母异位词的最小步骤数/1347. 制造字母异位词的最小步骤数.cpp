class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> ms;
        map<char, int> mt;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            ms[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            mt[t[i]]++;
        }
        for(auto it = mt.begin(); it != mt.end(); it++){
            char ch = it->first;
            if(mt[ch] >= ms[ch]){
                cnt += mt[ch] - ms[ch];
            }
        }
        return cnt;
    
    }
};