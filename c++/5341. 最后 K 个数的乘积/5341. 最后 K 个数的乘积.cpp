class ProductOfNumbers {
public:
    vector<int> se;
    int zero;
    ProductOfNumbers() {
        zero = 0;
        se.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            se.push_back(1);
            zero = se.size() - 1;
        }
        else se.push_back(num * se[se.size() - 1]);
    }
    
    int getProduct(int k) {
        if(se.size() - k - 1 < zero) return 0;
        return se[se.size() - 1] / se[se.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */