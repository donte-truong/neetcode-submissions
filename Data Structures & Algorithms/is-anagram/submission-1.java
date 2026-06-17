class Solution {
    public boolean isAnagram(String s, String t) {
        int[] sMap = new int[26];
        int matches = 26;
        for (int i = 0; i < s.length(); i++) {
            if (sMap[s.charAt(i) - 'a'] == 0) {
                matches -= 1;
            }
            sMap[s.charAt(i) - 'a'] += 1;
        }
        for (int j = 0; j < t.length(); j++) {
            if (sMap[t.charAt(j) - 'a'] == 0) {
                matches -= 1;
            }
            else if (sMap[t.charAt(j) - 'a'] == 1) {
                matches += 1;
            }
            sMap[t.charAt(j) - 'a'] -= 1;
        }
        return matches == 26;
    }
}
