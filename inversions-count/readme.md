# Inversions Count
Given an array of integers A[1, n], count the number of inversions in A.

for any given element A[i], the array contains an inversion for every element A[j] such that i < j and A[i] > A[j].

# Solution

The solution is based on a merge sort implementation.


In each subproblem encountered by the *merge* function, we define L and R as the left and right subarrays considered by the function. L and R are sorted, which grants us the following properties:

1. There are no inversions inside L and R, taken separately.
2. By definition, elements in R appear after the elements in L in the original array, so there can only be inversions from L to R.
3. given two elements L[x] and L[y] such that y > x, L[y] >= L[x], which means that L[y] holds at least the same number of inversions as L[x].


The algorithm defines the function *merge_inversions*, which sorts an array like the *merge* subroutine, but with additional steps:

- if an item is pushed from R and there are still unpushed items in L, add an inversion to the counter *incr*.

- every time an item is pushed from L, add *incr* to the total number of inversions.

- return the total number of inversions.


Every call of *inversions_count* sums the number of inversions from its recursive call and its respective call to *merge_inversions*.

## Time complexity
O(nlogn), only constant time operations are added to the default merge sort.

## Space complexity
O(n), auxiliary vector to store the sorted elements at every *inversions_count* call.

## Fenwick Tree Solution

- create an array C with the compressed coordinates of A -> O(nlogn)
- create a fenwick tree T of size n+1, initialized to 0, which stores the number of inversions.
- iterate C backwards with i
	- for each C[i] = x, set T[x] to 1. (NB: not using fenwick tree update ?)
	- add sum(x - 1) to the total number of inversions. 
	- which values in T are flipped first determines the number of inversions

## Time complexity
C and T both require O(nlogn) to be built.
Iterating C backwards + sum(i) operations on T = O(nlogn)

total: O(nlogn)

## Space complexity
T requires O(n) space.
C requires O(n) space.