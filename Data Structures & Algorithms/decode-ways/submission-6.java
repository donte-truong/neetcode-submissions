class Solution {
    public int numDecodings(String s) {
        int curr = 0;
        int first = 1;
        int second = 0;

        for (int i = s.length()-1; i >= 0; i--) {
            if (s.substring(i, i+1).equals("0")) {
                curr = 0;
            } else {
                curr = first;
            }
            
            if (i < s.length() - 1 && (s.substring(i, i+1).equals("1") || 
                (s.substring(i, i+1).equals("2") && "0123456".indexOf(s.substring(i+1, i+2)) != -1))
            ) {
                curr += second;
            }

            second = first;
            first = curr;
        }

        return first;
    }
}
