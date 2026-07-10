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

    int getValue(MountainArray &mountainArr, int idx) {
        if (idx < 0 || idx >= mountainArr.length()) return -1;
        return cache.contains(idx) ? cache[idx] : mountainArr.get(idx);
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int l = 0, r = mountainArr.length();
        int mid = 0;
        
        while (l < r) {
            mid = l + (r - l) / 2;

            int v1 = getValue(mountainArr, mid - 1);
            int v2 = getValue(mountainArr, mid);
            int v3 = getValue(mountainArr, mid + 1);

            if (v1 < v2 && v2 < v3) {
                l = mid + 1;
            } else if (v1 > v2 && v2 > v3) {
                r = mid;
            } else {
                break;
            }
        }

        l = 0; r = mid;

        while (l < r) {
            int m = l + (r - l) / 2;

            int val = getValue(mountainArr, m);
            if (val < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        if (getValue(mountainArr, l) == target) return l;
        
        l = mid; r = mountainArr.length();

        while (l < r) {
            int m = l + (r - l) / 2;

            int val = getValue(mountainArr, m);
            if (val > target) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return getValue(mountainArr, l) == target ? l : -1;

    }
};