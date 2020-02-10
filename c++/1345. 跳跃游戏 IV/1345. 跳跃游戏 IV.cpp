class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        bool visited[50005];
        int value[50006];
        bool jump[50005];
        memset(jump, true, sizeof(jump));
        memset(value, -1, sizeof(value));
        memset(visited, false, sizeof(visited));
        map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            m[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        value[0] = 0;
        while(!q.empty()){
            int next = q.front();
            //cout << next << ' ';
            q.pop();
            if(next - 1 >= 0 && visited[next - 1] == false){ 
                visited[next - 1] = true;
                q.push(next - 1);
                value[next - 1] = value[next] + 1;
                jump[next - 1] = true;
            }
            if(next + 1 < n && visited[next + 1] == false){
                visited[next + 1] = true;
                q.push(next + 1);
                value[next + 1] = value[next] + 1;
                jump[next + 1] = true;
            }
            if(jump[next] == true){
                vector<int> nextvec = m[arr[next]];
                for(int idx : nextvec) {
                    if(visited[idx] == false){
                        visited[idx] = true;
                        q.push(idx);
                        value[idx] = value[next] + 1;
                        jump[idx] = false;
                    }
                }
            }
            
        }
        //for(int i = 0; i < n; i++) cout << value[i] << ' ';
        //cout << endl;
        return value[n - 1];
    }
};