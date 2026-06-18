class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum = 0;
        int squareSum = 0;
        while(n > 0){
            int digit = n%10;
            sum += n%10;
            squareSum += digit*digit;
            n = n/10;
        }
        return ((squareSum - sum) >= 50);
    }
};