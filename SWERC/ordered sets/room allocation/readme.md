# Problem
Given a set A of integer pairs \<s, f\>, two pairs a,b can be grouped together if a.s < b.f.
Find the minimum number of groups you can use to store all the pairs.

For each pair, print the number of the group it has been inserted in.

# solution
ordered set A containing pairs ordered by a.
Use set B sto store b's of the incoming pairs.

for each incoming pair, B.lower_bound(a) returns an iterator to the first group where a > b.
If there is an element with such a b, substitute it with that of the new pair.
Otherwise insert the new b as a new element in the set.

the number of necessary groups is the final size of B. O(nlogn)
if we have to print the number of the group each element has been inserted in, requires O(n^2 logn)