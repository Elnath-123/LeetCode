bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}
class Solution {
public:
    vector< pair<int, int> > vec;
    int minSetSize(vector<int>& arr) {
        map<int, int> m;
        for(int i = 0; i < arr.size(); i++){
           m[arr[i]]++; 
        }
        for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
            vec.push_back(pair<int, int>(it->first, it->second));
        }
        sort(vec.begin(), vec.end(), cmp);
        int ans = 0;
        int len = arr.size();
        for(int i = 0; i < vec.size(); i++){
            if(len > arr.size() / 2){
                ans++;
                len -= vec[i].second;
            }
        }
        return ans;
    }
};