class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n+1 , 1e9);
            dp[0] = 0;
            vector<int> v;
            vector<int> streak;
            int k = 1;
            while(true){
                int score = (k*(k+1))/2;
                if(score>n){
                    break;
                }
                v.push_back(score);
                streak.push_back(k);
                k++;
            }
        for(int i=1;i<=n;i++){
            for(int j=0;j<v.size();j++){
                int score = v[j];
                int day = streak[j];

                if(i>=score){
                    dp[i] = min(dp[i] , day+1+dp[i-score]);
                }else{
                break;
                }
            }
        }

                return dp[n]-1;
    }
};