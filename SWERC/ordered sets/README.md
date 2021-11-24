# Ordered sets
Sets of unique elements that are ordered.
- Insert, delete, search in O(log n)

- begin() returns an iterator to the smallest element of the set
- end() returns an iterator to the biggest element
- find(k) returns an iterator to the element with key k -> O(logn)
- upper_bound(k) returns an iterator to the first element larger than k -> O(logn)
- lower_bound(k) returns an iterator to the first element larger than k -> O(logn)