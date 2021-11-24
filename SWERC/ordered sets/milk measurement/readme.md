# Problem
d c1 m
Every cow has initially produced the same g gallons of milk.
On day d, cow c1 produces m gallons compared to its previous measurement.
Only one cow can be measured each day.

The cow with the highest score is shown on a board.
If more than one cow chares the highest score, they are included in the board.
Determine number of days where the most productive cow changes. 

# Solution
insert measurements in an ordered map M where the day is the key, the value is a pair (cow, measurement), without overwriting duplicate days.
initialize unordered map C where keys are cows, values their total gallons, initialized to g.
create an empty multiset B, at every measurment we remove and insert a value in D.

for every pair (c,m) in M:
1. v = milk gallons previously produced by c, stored in C
2. remove one value v from D 
3. update the value in C with the new measurement v'
4. add one value v' to D

- for every duplicate in B, two cows have produced the same amount of milk.
- whenever an element is removed from B which is not the max, a cow that is not on the board has been measured.If the new score for that cow >= max, there will be a change.
- otherwise, one of the best cows has been measured. if its new value is < than the new max, there will be a change. if its value.
- last case is if its new value is >= than the new max, but less than its previous value, and second best cow has value equal to its new value. 

