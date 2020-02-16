class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        bool ans = false;
        while(true){
        int maxv = target[0];
        int maxi = 0;
        long long sum = 0;
            for(int i = 0; i < target.size(); i++){
                sum += target[i];
                if(target[i] > maxv){
                    maxv = target[i];
                    maxi = i;
                }
            }
            if(maxv == 1){
                ans = true;
                break;
            } 
            sum -= maxv;
            if(maxv - sum <= 0) {
                ans = false;  
                break;
            }
            target[maxi] = maxv - sum;
        }
        return ans;
    }
};