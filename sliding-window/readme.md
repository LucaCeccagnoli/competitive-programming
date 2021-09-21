## Problem
Given an array A[0, n-1] and an integer k, find the maximum of each subarray (window) of A of size k.

## Optimal solution
Use a Double-ended Queue.
The element at the front of the queue will be the one to report.

1. Initialize empity deque Q.
2. slide the window starting from [-k, -1], outside the array:
	1. remove head (element no longer in window).
	2. insert new item v in tail.
	3. remove all items above v until we find a larger one.
	4. head of Q is the max for the current window.


Time complexity: O(n)
- dominated by queue pops, which cost O(1) and every item is pushed and popped at most once.