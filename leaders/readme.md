# Leaders in an array
Write a program to print all the leader items in an array.
A leader is an item that is greater than all the items to its right.


## Solution

Iterate the array backwards and save the highest value foud. This way we know that if an element is greater than the current highest, it will also be greater than all the ones we already iterated over.

- Time complexity: O(n)
    - one iteration over array of size n

- Space complexity: O(n)
    - we only use one extra variable to store the highest value