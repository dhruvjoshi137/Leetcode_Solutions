class ProductOfNumbers {
private:
    vector<int> prefix;  // prefix product store karne ke liye

public:
    ProductOfNumbers() {
        prefix = {1};  
    }

    void add(int num) {
        if (num == 0) {
            prefix = {1};  // zero aaya toh reset karna padega
        } else {
            prefix.push_back(prefix.back() * num); //last element ka num ke sath multiply karke prefix mein store kar diya 
        }
    }

    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) return 0;  // Agar reset ke baad k bada ho gaya toh 0
        return prefix[n - 1] / prefix[n - 1 - k];
    }
};