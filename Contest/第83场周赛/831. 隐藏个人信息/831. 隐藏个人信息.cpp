class Solution {
public:
    const int email = 1;
    const int phone = 2;
    string lower(string S){
        for(int i = 0; i < S.size(); i++){
            if(S[i] >= 'A' && S[i] <= 'Z'){
                S[i] = S[i] + 'a' - 'A';
            }
        }
        return S;
    }
    string maskPII(string S) {
        int type = 2;
        int atloc = 0;
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '@'){
                type = 1;
                atloc = i;
                break;
            }
        }
        string ans;
        /* email */
        if(type == 1){
            S = lower(S);
            ans += S[0];
            ans += "*****";
            ans += S[atloc - 1];
            ans += S[atloc];
            ans += S.substr(atloc + 1, S.size() - atloc);
        }
        else{
            string temp;
            for(int i = 0; i < S.size(); i++){
                if(isdigit(S[i])){
                    temp += S[i];
                }
            }
            for(int i = temp.size() - 1; i >= temp.size() - 4; i--){
                ans += temp[i];
            }
            ans += '-';
            ans += "***-***";
            if(temp.size() > 10){
                ans += '-';
                for(int i = 0; i < temp.size() - 10; i++){
                    ans += '*';
                }
                ans += '+';
            }
            reverse(ans.begin(), ans.end());
        }
        return ans;
    }
};