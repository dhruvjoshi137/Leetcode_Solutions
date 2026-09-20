class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int X = max(x1 , min(xCenter , x2));
        int Y = max(y1 , min(yCenter , y2));

        long long dx = xCenter - X;
        long long dy = yCenter - Y;

        return dx * dx + dy * dy <= 1LL * radius * radius;
    }
};