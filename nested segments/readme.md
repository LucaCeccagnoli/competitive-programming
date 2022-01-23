# Problem
Given n segments <li, ri> with no overlapping end points.
For each segment, find the number of other segments it fully overlaps.

# Solution
1. Create an array B of size 2n with the compressed coordinates of the segments.
2. Turn B into a  fenwick tree.
	1. set every starting position to 0
	2. set every ending position to 1.
	3. a segment with an ending position of 1 has not been processed.
4. sweep line to process segment from left to right, based on starting position.
	1. On visiting an endpoint <l, r>
		1. set B[r] = 0
			-  removes the right endpoint
			-  means that the segment has been processed
		2. a completely overlapped segment has the following properties:
			1. start > l
				-  means it has not been processed
			2. end < r
				-  sum(r) gives all the segments that end before position r
				-  segments before l have already been set to 0, so they have already been processed.

## correctness
if we visit <l,r> and compute sum(r)
- the value of sum(r) is the number of segments that end between l and r
- if one of these segments ended before l, it would have already been processed.

## time complexity
coordinate compression = O(nlogn)
2n fenwick tree queries = O(nlogn)

total = O(nlogn)

## space complexity
fenwick tree = O(n)