# Kadane's Algorithm
Given an array containing both negative and positive integers, find the contiguous sub-array with maximum sum.

## Sub-optimal solution
Compare the sum of all possible subarrays. Requires three nested loops.

Time complexity: O(n^3).

Space complexity: O(n).

## Optimal solution
Iterate through the array and keep track of the sum with two variables: **accumulator** and **current_max**. 

**accumulator** contains the sum of the subarray that is currently being analyzed. If an item is found with a value higher than the current sum, we set the accumulator to this item's value, as if we were to start analyzing another subarray, because the previous one is clearly not the best anymore. Since accumulator can have its value reduced, we need **current_max** to stores the maximum sum found up to this point.

Time complexity: O(n), we only iterate through the array once.

Space complexity: O(n).
