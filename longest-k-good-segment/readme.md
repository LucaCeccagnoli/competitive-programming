# Problem

Given A[1,n] of integers and value k
A subarray is called **k-good** if it contains no more than k different values.

find the longest k-good subarray in A.S (return indexes)

# Solution

Iterate throught the array using a sliding window.
Use a dictionary K where the keys represent the distinct integers in the current window, and values store their respective number of occurrencies.
When moving the head of the window, insert the new item as a key in K, or increment its value if it is already present.
If the number of keys (with value > 0) exceeds k, move the tail forward until a key in K reaches value 0.

### time complexity
By implementing the dictionary as a hash table, search, insert and delete operations take constant time on average.

Every item in A can be accessed at most once by the head and at most once by the tail, so 2n times in total.

total time complexity = O(n)

### space complexity
The hash table will contain at most O(n) elements, O(k) if we remove the keys that reach a value of zero.
