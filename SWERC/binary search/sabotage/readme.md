# Problem
Given an array A[0,n-1] of n integer values, remove a contiguous part of the array to minimize the average value of the remaining elements.
Cannot remove the first or last elements. Must remove at least one number.

Find the minimum possible average m

# Solution
find average of values in A[0,n-1] = a

removing an element i < a will increase m 


- subarrays that have negative sum have also negative average


# Best solution
possible(double guess): returns true if the sum of elements in A[1,n-1]                                                        

