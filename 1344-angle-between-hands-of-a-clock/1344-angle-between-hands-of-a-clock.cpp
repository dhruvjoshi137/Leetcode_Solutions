class Solution {
public:
    double angleClock(int hour, int minutes) {
        //we will convert the 12 to 0 
        if(hour == 12) hour = 0;

        //the hour hand moves 30deg/hour  + 0.5 deg/min
        //and the minute hand moves 6 deg/min

        double AngleOfHour = (hour*30) + (minutes*0.5);
        double AngleOfMins = (minutes*6);

        //now i will calculate the absolute difference between the two
        double finalAngle = abs(AngleOfHour - AngleOfMins);


        // now as the question has stated , we have to return the smaller angle
        return min(finalAngle , 360 - finalAngle);

    }
};