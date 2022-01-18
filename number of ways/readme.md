# Problem

Given an array A of n integers, find the number of ways you can divide it in 3 subarrays such that the sum of the elements in each subarray is equal to the others

# Solution
Given the sum of A = m
By definition, every subarray must have sum s = m/3
compute vector S of prefix sums.
For each i such that S[i] is a multiple of s, add 1 to the number of ways we can subdivide A.

### time complexity
sum A and Iterate it once:
O(n)