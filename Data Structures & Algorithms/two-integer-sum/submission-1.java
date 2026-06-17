class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];
        HashMap<Integer, Integer> targetMap = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int targetValue = target - nums[i];
            if (targetMap.containsKey(nums[i])) {
                result[0] = targetMap.get(nums[i]);
                result[1] = i;
                return result;
            }
            targetMap.put(targetValue, i);
        }
        return result;
    }
}
