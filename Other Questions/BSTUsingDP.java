import java.util.*;

// Dynamic Programming Approach
class Solution {
    public int splitArray(int[] nums, int m) {
        int[][] dp = new int[nums.length][m];
        int totalSum = 0;
        for (int i = 0; i < nums.length; i++) {
            totalSum += nums[i];
        }
        return getMaxSubarraySum(nums, dp, m, 0, totalSum);
    }
    
    private int getMaxSubarraySum(int[] nums, int[][] dp, int m, int idx, int totalSum) {
        if (m == 1) {
            return totalSum;
        }
        if (dp[idx][m - 1] > 0) {
            return dp[idx][m - 1];
        }
        
        int sum = 0;
        int minSum = Integer.MAX_VALUE;
        for (int i = idx; i <= nums.length - m; i++) {
            sum += nums[i];
            minSum = Math.min(minSum, 
                Math.max(sum, getMaxSubarraySum(nums, dp, m - 1, i + 1, totalSum - sum)));
        }
        dp[idx][m - 1] = minSum;
        return minSum;
    }
}

class MainRunner {
	public static void main(String args[]) {
		Solution s = new Solution();
		int MinCost=0;
        int ar[] = {8,4,12,2,6,10,14,1,3,5,7,9,11,13,15};
		MinCost = s.splitArray(ar, 15);
		System.out.println(MinCost);
	}
}