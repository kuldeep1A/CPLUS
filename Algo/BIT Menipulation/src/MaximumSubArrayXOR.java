/**
 * In this implementation, we use a Trie data structure to store the prefix XOR values. The TrieNode class
 * represents a node in the Trie, and the Trie class represents the Trie itself. The insert method is used
 * to insert a number into the Trie, and the findMaxXOR method finds the maximum XOR value of a number in
 * the Trie. The findMaximumSubarrayXOR function takes an array of numbers (nums) as input and returns the
 * maximum XOR value of a subarray. It iterates over the input array, calculates the prefix XOR value up to
 * the current element, inserts it into the Trie, and finds the maximum XOR value using the findMaxXOR method.
 * Finally, it returns the maximum XOR value of a subarray. In the example main method, we have an
 * array [3, 10, 5, 25, 2, 8].
 */

public class MaximumSubArrayXOR{
    // Trie Node
    static class TrieNode{
        TrieNode[] children;

//        TrieNode(){
//            children = new TrireNode[2];
//        }
    }

    // Trie class
    static class Trie{
        TrieNode root;

        Trie(){
            root = new TrieNode();
        }

        // Insert a number into Trie
        void insert(int num){
            TrieNode curr = root;

            for(int i = 31; i >= 0; i--){
                int bit = (num >> i) & 1;

                if(curr.children[bit] == null){
                    curr.children[bit] = new TrieNode();
                }
                curr = curr.children[bit];
            }
        }

        // Find the maximum XOR value of a number in Trie
//        void findMaxXOR(){}
    }
    // Function to find the maximum XOR value of a subarray
//    static int findMaximumSubarrayXOR(int[] nums){
//        int n = nums.length;
//        int maxSubarrayXOR = Integer.MIN_VALUE;
//        int prefixXOR = 0;
//
//        Trie trie = new Trie();
//        trie.insert(0);
//
//        for(int i = 0; i < n; i++){
//            prefixXOR ^= nums[i];
//            trie.insert();
//        }
//
//    }

    public static void main(String[] args) {
        int[] nums = {3, 10, 5, 25, 2, 8};
//        int maxSubarrayXOR = findMaximumSubarrayXOR(nums);
//        System.out.println("Maximum XOR value of a subarray: " + maxSubarrayXOR);

    }
}