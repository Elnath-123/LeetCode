class Solution {
public:
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
    int myAtoi(string str) {
        string chv;
        int i = 0;
        int sign;
        while(str[i] == ' ' && i < str.size()) i++;
        if(str[i] == '+' || str[i] == '-'){
            sign = str[i] == '+' ? 0 : 1;
            i++;
            while(isDigit(str[i])) chv.push_back(str[i++]);
        }
        else if(isDigit(str[i])){
            sign = 0;
            while(isDigit(str[i])) chv.push_back(str[i++]);    
        }
        else{
            return 0;
        }
        long long px = 1;
        long long ans = 0;
        int j = 0;
        while(chv[j] == '0') j++;
        chv = chv.substr(j, chv.size() - j);
        if(chv.size() > 12 && sign == 0) return 2147483647;
        if(chv.size() > 12 && sign == 1) return -2147483648;
        for(j = chv.size() - 1; j >= 0; j--){
            ans += px * (chv[j] - '0');
            px *= 10;
        }
        if((sign == 0 && ans > 2147483647LL) || chv.size() > 12){
            return 2147483647;
        }
        if(sign == 1 && ans > 2147483648LL || chv.size() > 12){
            return -2147483648;
        }
        if(sign == 1){
            return -ans;
        }else{
            return ans;
        }

    }
};