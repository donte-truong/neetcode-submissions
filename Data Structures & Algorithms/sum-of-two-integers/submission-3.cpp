class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while (b) {
            carry = (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
