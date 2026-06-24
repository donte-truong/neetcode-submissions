class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int l = 0;

        for (int r = 1; r < asteroids.size(); r++) {
            while (l >= 0 && asteroids[l] > 0 && asteroids[r] < 0) {
                if (asteroids[l] > abs(asteroids[r])) {
                    asteroids[r] = 0;
                    break;
                } 
                if (asteroids[l] == abs(asteroids[r])) {
                    asteroids[r] = 0;
                    l--;
                    break;
                }
                l--;
            }
            if (asteroids[r] != 0) {
                asteroids[++l] = asteroids[r];
            }
        }

        asteroids.resize(l + 1);
        return asteroids;
    }
};