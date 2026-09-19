class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        
        // Find closest x-coordinate on rectangle
        int closestX = max(x1, min(xCenter, x2));
        
        // Find closest y-coordinate on rectangle
        int closestY = max(y1, min(yCenter, y2));
        
        // Distance between circle center and closest point
        long long dx = xCenter - closestX;
        long long dy = yCenter - closestY;
        
        return dx * dx + dy * dy <= 1LL * radius * radius;
    }
};