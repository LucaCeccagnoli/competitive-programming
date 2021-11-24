# Problem
n points in a line, which can move in one of both directions.

every point i has:
xi = position on n
vi = max speed

compute the minimum time needed to gather everyone at some point in the road. Doesn't have to be an integer coordinate.

- a point stop after reaching the chosen point.

# Solution
given a point p, time ti that i requires to get to p = |xi - p| / vi
find the point p with binary search in [xi, xj] where i and j are the farthest points.
minimum time for point p is given by the maximum ti.

when to stop?

## time complexity
find farthest points -> O(n)
binary search for point p -> O(logm) depends on chosen precision
find max between points -> O(n)

O(nlogm)