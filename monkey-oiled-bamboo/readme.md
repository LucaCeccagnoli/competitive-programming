# problem
Monkey climbs tree, with an initial strength of k.
the monkey has to jump through every branch of the bamboo tree, placed at different heights.

if the monkey jumps up k units, decrement max k by one. If the jump is less than k, don't decrement.

Given an array A of size n with 1 <= n <= 10 with the height of each rung (increasing), find the minimum k required to climb the tree.

# solution
iterate A backwards and keep track of the difference between each value. The minimum k is given by the max difference between the rungs.

## complexity
O(n)