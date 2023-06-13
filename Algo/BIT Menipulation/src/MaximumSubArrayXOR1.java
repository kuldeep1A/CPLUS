/**
 * In this implementation, the findMaximumSubarrayXOR function takes an array of numbers (nums) as input and returns the
 * maximum XOR value of a subarray.
 * The function uses two nested loops to iterate over all possible subarrays. For each subarray,
 * it calculates the XOR of all elements and updates the maxSubarrayXOR if the current XOR value is greater.
 * This way, it keeps track of the maximum XOR value encountered so far.
 * In the example main method, we have an array [3, 10, 5, 25, 2, 8].
 * The program calculates the maximum XOR value of a
 * subarray using the findMaximumSubarrayXOR1 function and prints the result.
 */
public class MaximumSubArrayXOR1 {
    public static int findMaximumSubarrayXOR(int[] nums){
        int maxSubarrayXOR = 0;
        int n = nums.length;
        for(int i = 0; i < n; i++){
            int currXOR = 0;
            for(int j = i; j < n; j++){
                currXOR ^= nums[j];
                System.out.println(nums[j] + " bit are : " + currXOR);
                maxSubarrayXOR = Math.max(currXOR, maxSubarrayXOR);
            }
        }
        return maxSubarrayXOR;
    }
    public static void main(String[] args) {
        int[] nums = {3, 10, 5, 25, 2, 8};
        int maxSubarrayXOR = findMaximumSubarrayXOR(nums);
        System.out.println("Maximum value of a Subarray: " + maxSubarrayXOR);
    }
}