# Problem
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

# Solution
Use an unordered map C to store the indexes of complementary numbers to reach target for every number that is read from nums. Stop when you find a number whose complementary is already in C.

## time complexity
O(n), assuming that the map lookup and insert operations require O(1).
