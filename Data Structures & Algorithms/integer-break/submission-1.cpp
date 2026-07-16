class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;

        int multiples = n / 3;
        int remainder = n % 3;

        return (remainder == 1 ?
            pow(3, multiples - 1) * 4 :
            pow(3, multiples) * ((remainder + 2) / 2)
        );
    }
};