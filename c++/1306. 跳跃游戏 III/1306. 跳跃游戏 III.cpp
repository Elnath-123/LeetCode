class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        int n = arr.size();
        bool visited[50005];
        memset(visited, false, sizeof(visited));
        q.push(start);
        bool flag = false;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(arr[cur] == 0){
                flag = true;
                break;
            }

            if(cur + arr[cur] < n && !visited[cur + arr[cur]]){
                visited[cur + arr[cur]] = true;
                q.push(cur + arr[cur]);
            }

            if(cur - arr[cur] >= 0 && !visited[cur - arr[cur]]){
                visited[cur - arr[cur]] = true;
                q.push(cur - arr[cur]);
            }
        }
        return flag;
    }
};