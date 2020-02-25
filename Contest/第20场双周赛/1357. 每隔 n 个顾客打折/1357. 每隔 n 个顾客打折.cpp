class Cashier {
public:
    int freq;
    int disc;
    vector<int> products;
    vector<int> prices;
    map<int, int> m;
    int cnt;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        cnt = 0;
        freq = n;
        disc = discount;
        this->products = products;
        this->prices = prices;
        for(int i = 0; i < products.size(); i++){
            m[products[i]] = i;
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        
        double sum = 0;
        for(int i = 0; i < amount.size(); i++){
            sum += amount[i] * prices[m[product[i]]];
        }
        if(cnt % freq == 0){
            sum = sum - (disc * 1.0 * sum) / 100;
        }
        return sum;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */