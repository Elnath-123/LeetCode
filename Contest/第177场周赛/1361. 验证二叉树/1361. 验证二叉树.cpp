class Solution {
public:
    int point[10005];
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int ans = true;
        for(int i = 0; i < n; i++){
            if(leftChild[i] != -1) 
                point[leftChild[i]] ++;
            if(rightChild[i] != -1)
                point[rightChild[i]] ++;
            
        }
        for(int i = 0; i < n; i++){
            if(point[i] > 1){
                ans = false;
                break;
            
            }
        }
        
        int in = 0;
        for(int i = 0; i < n; i++){
            if(point[i] == 0) in++;
        }
        if(in > 1) ans = false;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(leftChild[i] == j && (leftChild[j] == i || rightChild[j] == i)){
                    ans = false;
                    break;
                }
            }
        }
        return ans;
    }
};