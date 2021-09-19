# Missing item in array
Given array of size n-1 , containing unordered integers from 1 to n, find the missing number.

## Solution
The summation of numbers from 1 to n is given by the formula n(n+1)/2

We can find the missing number by calculating the sum of the array elements and subtracting it to the formula.

Time complexity: O(n).
- the array is iterated once to sum its elements.


Space complexity: O(1)
