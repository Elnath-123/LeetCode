class Solution {
public
    struct Interval{
        int l, r;
        Interval(int l, int r)  l(l), r(r){}
        Interval(){}
    };
    vectorInterval v;
    static bool cmp(Interval a, Interval b){
            return a.r  b.r;
    }
    int maxEvents(vectorvectorint& events) {
        for(auto i  events){
            v.push_back(Interval(i[0], i[1]));
        }
        sort(v.begin(), v.end(), cmp);
        bool visited[100005];
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        for(int i = 0; i  events.size(); i++){
            int num = v[i].l;
            while(visited[num] == true){
                num++;
            }
            if(num = v[i].r) {
                visited[num] = true;
                cnt++;
            }
        }
        return cnt;
    }
};