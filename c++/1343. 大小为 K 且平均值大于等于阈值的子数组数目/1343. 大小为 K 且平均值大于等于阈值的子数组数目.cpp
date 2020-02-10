class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        //sort(arr.begin(), arr.end());
        int l = 0;
        int r = k - 1;
        int ll = l;
        int rr = r;
        int ans = 0;
        int sum = 0;
        for(int i = l; i <= r; i++){
            sum += arr[i];
        }
        if(sum / k >= threshold) ans++;
        l++, r++;
        while(r < arr.size()){
            sum -= arr[ll];
            sum += arr[r];
            if(sum / k >= threshold){ans++; }
            l++, r++;
            ll++, rr++;
        }
        
        return ans;
    }
};