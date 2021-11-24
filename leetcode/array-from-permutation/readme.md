# Problem
Difficulty: easy

Given a **zero-based permutation** `nums` (**0-indexed**), build an array `ans` of the **same length** where `ans[i] = nums[nums[i]]` for each `0 <= i < nums.length` and return it.

A **zero-based permutation** `nums` is an array of **distinct** integers from `0` to `nums.length - 1` (**inclusive**).

# Solution
1. create a new array and save the `nums[nums[i]]` values there.

**time complexity:** O(n)
**space complexity:** O(n)