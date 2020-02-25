class Solution {
public:
    vector<int> closestDivisors(int num) {
        int num1 = num + 1;
        int num2 = num + 2;
        int ans = 1900000000;
        int ans1 = -1;
        int ans2 = -1;
        if(num == 1) return {1, 2};
        for(int i = 2; i <= sqrt(num1); i++){
            if(num1 % i == 0){
                int a = i;
                int b = num1 / i;
                if(abs(a - b) < ans){
                    ans = abs(a - b);
                    ans1 = a;
                    ans2 = b;
                }
            }    
        }
        for(int i = 2; i <= sqrt(num2); i++){
            if(num2 % i == 0){
                int a = i;
                int b = num2 / i;
                if(abs(a - b) < ans){
                    ans = abs(a - b);
                    ans1 = a;
                    ans2 = b;
                }
            }    
        }
        return {ans1, ans2};
        
    }
};