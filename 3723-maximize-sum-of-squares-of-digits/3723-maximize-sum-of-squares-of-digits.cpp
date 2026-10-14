class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if (sum > 9LL * num) {
            return "";
        }
        
        int nines = sum / 9;
        int rem = sum % 9;
        int zeros = num - nines - (rem > 0 ? 1 : 0);
        
        string result = "";
        result.reserve(num);
        
        result.append(nines, '9');
        if (rem > 0) {
            result.push_back('0' + rem);
        }
        result.append(zeros, '0');
        
        return result;
    }
};
