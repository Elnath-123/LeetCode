struct Rank{
    int index;
    int num;
    Rank() :index(0), num(0){}
};

bool cmp(Rank a, Rank b){
    if(a.num != b.num)
        return a.num < b.num;
    return a.index < b.index;
}
class Solution {
public:
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        Rank rk[105];
        int cnt = 0;
        for(int i = 0; i < mat.size(); i++){
            rk[i].index = i;
            for(int j = 0; j < mat[0].size(); j++){
                rk[i].num += mat[i][j]; 
            }
        }
        sort(rk, rk + mat.size(), cmp);
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(rk[i].index);
        }
        return ans;
    }
};