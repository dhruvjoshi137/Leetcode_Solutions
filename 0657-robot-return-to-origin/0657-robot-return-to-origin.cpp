class Solution {
public:
    bool judgeCircle(string moves) {
        int vertical = 0;
        int horizontal = 0;
        for(int i=0;i<moves.length();i++){
            char move = moves[i];

            if(move == 'R'){
                horizontal+=1;
            }else if(move == 'L'){
                horizontal-=1;
            }else if(move == 'U'){
                vertical+=1;
            }else if(move == 'D'){
                vertical-=1;
            }
        }

        if(horizontal == 0 && vertical ==0){
            return true;
        }else{
            return false;
        }
    }
};