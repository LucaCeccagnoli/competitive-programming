## Problem
Given an array A[0, n-1] having *distinct* elements, the goal is to find the next greater element for each element of the array in order of their appearence in the array.


## solution
- create a stack S
- push A[0] to S
- next = A[1]
- iterate through A
	- while next > S.top
		- pop S, next is the NLE for that element
		- print next
	- Push next element to S
- pop all elements in S, print -1 for each one.

### time complexity
every element is pushed and popped from the stack once.
O(n)

### space complexity
No extra space.
O(n)