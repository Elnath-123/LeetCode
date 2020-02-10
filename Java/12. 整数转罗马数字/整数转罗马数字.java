class Solution {
    public String intToRoman(int num) {
        String ans = "";
        while(num >= 1000){
            ans += 'M';
            num -= 1000;
        }
        int c2, c1, c0;
        c2 = num / 100;
        c1 = num / 10 % 10;
        c0 = num % 10;
        if(c2 == 9){
            ans += "CM";
            num -= 900;
        }else if(c2 == 4){
            ans += "CD";
            num -= 400;
        }else{
            if(c2 >= 5){
                ans += "D";
                num -= 500;
            }
            while(num >= 100){
                ans += "C";
                num -= 100;
            }
        }
        if(c1 == 9){
            ans += "XC";
            num -= 90;
        }else if(c1 == 4){
            ans += "XL";
            num -= 40;
        }else{
            if(c1 >= 5){
                ans += "L";
                num -= 50;
            }
            while(num >= 10){
                ans += "X";
                num -= 10;
            }
        }

        if(c0 == 9){
            ans += "IX";
            num -= 9;
        }else if(c0 == 4){
            ans += "IV";
            num -= 4;
        }else{
            if(c0 >= 5){
                ans += "V";
                num -= 5;
            }
            while(num > 0){
                ans += "I";
                num--;
            }
        }
        return ans;
    }
}