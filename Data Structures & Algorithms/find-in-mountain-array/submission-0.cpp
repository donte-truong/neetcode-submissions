/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {

private:  
    unordered_map<int, int> cache;
    int getValue(MountainArray &mountainArr, int index) {
        if (index < 0 || index > mountainArr.length()) 
            return -1;

        return cache.contains(index) ? cache[index] : mountainArr.get(index);
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();

        // Find peak
        int peak = 0;

        int l = 0, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            int valL = getValue(mountainArr, m - 1);
            int valM = getValue(mountainArr, m);
            int valR = getValue(mountainArr, m + 1);

            if (valL < valM && valR < valM) {
                peak = m;
                break;
            } else if (valL > valM) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        // Search left
        l = 0, r = peak;
        while (l < r) {
            int m = l + (r - l) / 2;
            int val = getValue(mountainArr, m);

            if (val == target) {
                return m;
            } else if (val < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        // Search right
        l = peak, r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            int val = getValue(mountainArr, m);
            
            if (val == target) {
                return m;
            } else if (val < target) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return -1;

    }
};