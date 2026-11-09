class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;

        for(int a=1;a<=n;a++){
            for(int b =1;b<=n;b++){
                int sq = a*a + b*b;
                int s = sqrt(sq);

                if(s <= n && s * s == sq){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};