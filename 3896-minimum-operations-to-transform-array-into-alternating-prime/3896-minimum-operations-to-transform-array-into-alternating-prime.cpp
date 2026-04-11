class Solution {
public:

    bool primeHaiKya(int n ){
        if(n <= 1) return false;
        if(n == 2) return true;
        if(n % 2 == 0) return false; //coz only even prime number is 2 which we have already checked above

        for(int i=3; i*i <=n; i+=2){
            if(n%i ==0){
                return false;
        }
        }
            return true;
    }
    int minOperations(vector<int>& nums) {

        int ops = 0;

        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            if(i%2 == 0){
                // i need prime numbers at even indices
                while(!primeHaiKya(num)){
                    //num and ops badhate jao until i get a prime num
                    num++;
                    ops++;
                }
            }else{
                //here i need a non prime num
                while(primeHaiKya(num)){
                    num++;
                    ops++;
                }
            }
        }
        return ops;
    }
};