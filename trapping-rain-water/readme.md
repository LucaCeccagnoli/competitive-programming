## Problem
Given an array A of N non-negative integers representing the height of blocks. If the width of each block is 1, compute how much water can be trapped between the blocks during rainy season.

## Solution
the total trapped rainwater can be seen as the intersection between:
- the water that would be trapped by adding an infinite wall to the left
- the water that would be trapped by addin an infinite wall to the right

1. two vectors:
	1. left_max: store the maximum height of trapped water from the left up to index i
	2. right_max: store the maximum height of trapped water from the rigth up to index i
2. total water is given by summing for each i:
	min(left_max[i], right_max[i]) - A[i]

### time complexity


### space complexity