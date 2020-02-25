class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int> > ans;
        if(S.size() <= 2) return ans;
        for(int i = 0; i < S.size() - 2; i++){
            if(S[i] == S[i + 1] && S[i + 1] == S[i + 2]){
                int start = i;
                while(S[i] == S[i + 1]) i++;
                ans.push_back({start, i});
            }    
        }
        return ans;
    }
};