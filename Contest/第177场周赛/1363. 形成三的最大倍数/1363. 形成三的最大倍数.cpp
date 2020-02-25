class Solution {
public:
    static bool cmp(int a, int b){
        return a > b;
    }
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end());
        string ans;
        queue<int> zero;
        queue<int> one;
        queue<int> two;
        int sum = 0;
        bool exist = true;
        for(int i = 0; i < digits.size(); i++){
            if(digits[i] % 3 == 0) zero.push(digits[i]);
            if(digits[i] % 3 == 1) one.push(digits[i]);
            if(digits[i] % 3 == 2) two.push(digits[i]);
            sum += digits[i];
        }
        vector<int> anst;
        if(sum == 0) return "0";
        if(sum % 3 == 0){
            while(!zero.empty()){
                anst.push_back(zero.front());
                zero.pop();
            }
            while(!one.empty()){
                anst.push_back(one.front());
                one.pop();
            }
            while(!two.empty()){
                anst.push_back(two.front());
                two.pop();
            }
        }
        else if(sum % 3 == 1){
            if(one.size() >= 1){
                int temp1 = one.front();
                one.pop();
                sum -= (temp1);
                if(sum == 0) exist = false;
                if(sum % 3 == 0){
                     while(!zero.empty()){
                        anst.push_back(zero.front());
                        zero.pop();
                    }
                    while(!one.empty()){
                        anst.push_back(one.front());
                        one.pop();
                    }
                    while(!two.empty()){
                        anst.push_back(two.front());
                        two.pop();
                    }
                }
            }else if(two.size() >= 2){
                int temp1 = two.front();
                two.pop();
                int temp2 = two.front();
                two.pop();
                sum -= (temp1 + temp2);
                if(sum == 0) exist = false;
                if(sum % 3 == 0){
                     while(!zero.empty()){
                        anst.push_back(zero.front());
                        zero.pop();
                    }
                    while(!one.empty()){
                        anst.push_back(one.front());
                        one.pop();
                    }
                    while(!two.empty()){
                        anst.push_back(two.front());
                        two.pop();
                    }
                }
            }else{
                exist = false;
            }
        }else if(sum % 3 == 2){
           if(two.size() >= 1){
                int temp1 = two.front();
                two.pop();
                sum -= (temp1);
                if(sum == 0) exist = false;
                if(sum % 3 == 0){
                    while(!zero.empty()){
                        anst.push_back(zero.front());
                        zero.pop();
                    }
                    while(!one.empty()){
                        anst.push_back(one.front());
                        one.pop();
                    }
                    while(!two.empty()){
                        anst.push_back(two.front());
                        two.pop();
                    }
                }
            }
            else if(one.size() >= 2){
                int temp1 = one.front();
                one.pop();
                int temp2 = one.front();
                one.pop();
                sum -= (temp1 + temp2);
                if(sum == 0) exist = false;
                if(sum % 3 == 0){
                     while(!zero.empty()){
                        anst.push_back(zero.front());
                        zero.pop();
                    }
                    while(!one.empty()){
                        anst.push_back(one.front());
                        one.pop();
                    }
                    while(!two.empty()){
                        anst.push_back(two.front());
                        two.pop();
                    }
                }
            }
            else{
                exist = false;
            }
        }
        if(exist == false) return "";
        sort(anst.begin(), anst.end(), cmp);
        for(int i = 0; i < anst.size(); i++){
            ans += anst[i] + '0';
        }
        return ans;
    }
};