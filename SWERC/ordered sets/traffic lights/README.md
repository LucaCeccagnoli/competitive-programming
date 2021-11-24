# Problem

Given an ordered set of integers A, initially empty, whose elements must have values <= x, n integers from a set N are added to it in succession. Every time an integer is added, print the length of the longest space without integers in A.

# Solution

Create an ordered multiset D containing the gaps between inserted elements and update it while adding elements to A.
At every addition, a gap will be split in two, so you have to remove the previous one from the multiset and add the two new ones. 

## time complexity
All operations required to process the addition of a number to A require O(logn).

total: O(nlogn)

## space complexity
A can have at most size x.
At every step we remove an item from D and insert two, so it will have size 2n.

