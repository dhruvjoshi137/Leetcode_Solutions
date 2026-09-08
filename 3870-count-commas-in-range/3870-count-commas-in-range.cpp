class Solution {
public:
    int countCommas(int n) {
        int commas = 0;
        while(n>=1000){
            commas += (n - 1000 + 1);
            n = n/1000;
        }
        return commas;
    }
};