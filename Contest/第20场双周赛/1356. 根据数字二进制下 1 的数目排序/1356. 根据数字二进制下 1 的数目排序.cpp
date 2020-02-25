class Solution {
public:
    struct Node{
        int val;
        int cnt;
        int idx;
        Node(int val, int cnt, int idx){
            this->val = val;
            this->idx = idx;
            this->cnt = cnt;
        }
    };
    static bool cmp(Node a, Node b){
        if(a.cnt != b.cnt)
            return a.cnt < b.cnt;
        else
            return a.val < b.val;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> ans;
        vector<Node> tmp;
        for(int i = 0; i < arr.size(); i++){
           int num = arr[i];
           int cnt = 0;
           while(num > 0){
                cnt += num % 2;
                num /= 2;
           }
           tmp.push_back(Node(arr[i], cnt, i));
       }
       sort(tmp.begin(), tmp.end(), cmp);
       for(int i = 0; i < tmp.size(); i++){
           ans.push_back(tmp[i].val);
       }
       return ans;
    }
};