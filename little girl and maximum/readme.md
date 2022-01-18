# problem
Given an array A of n integers (also works with floats), and a set Q of q queries such that:
query(i, j) = [[prefix sum#rangeSum|rangeSum(i,j)]]

find a permutation of A such that the results of the queries are maximized

# solution
Find how many times every element of A appears in the queries using a frequency array F.
Sort A and F, then greedily substitute the highest value of A in the most frequent position that is not already occupied.

You can compute the frequency array with a sweep line approach or using prefix sum.

This example uses the prefix sum approach:
Every element in A also stores how many queries start and end on its position.
Initialize a counter *freq* to 0.
For every element a in A, for each query that starts in a, increment freq and save it as the frequency for that element in F.
For each query that ends in a, decrement freq, then go to the next element.

## time complexity
Computing the frequency array requires O(n + q)
Then A and F need to be sorted and scanned once: O(nlogn)

total: O(nlogn)

## space complexity
array A to store elements and queries: O(n)
frequency array F: O(n)
permutated array: O(n)

total: O(n)