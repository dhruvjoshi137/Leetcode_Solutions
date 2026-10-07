class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        int cnt = 0;
        for(int i=0;i<hours.size();i++){
            for(int j=i+1;j<hours.size();j++){
                ans = hours[i] + hours[j];
                if(ans % 24 == 0) cnt ++;
            }
        }
    return cnt;
    }
};