class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int length = flowerbed.size();
        
        for (int i = 0; i < length; ++i) {
            bool left_empty = (i == 0) || (flowerbed[i - 1] == 0);
            bool right_empty = (i == length - 1) || (flowerbed[i + 1] == 0);
            
            if (flowerbed[i] == 0 && left_empty && right_empty) {
                flowerbed[i] = 
                n--;
            }
            
            if (n <= 0) {
                return true;
            }
        }
        
        return n <= 0;
    }
};
