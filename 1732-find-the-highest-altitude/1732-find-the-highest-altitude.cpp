class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAltitude = 0; //this will track the current altitude of the biker
        int maxAltitude = 0; //this will track the maximum altitude the biker has reached so far

        for(int x : gain){
            //iterate through the array
            currAltitude += x;
            //calculate altitude at each point
            maxAltitude = max(currAltitude , maxAltitude);
            //update the global maximum
        }
        return maxAltitude;
    }
};