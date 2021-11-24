# Problem
N tasks <s,f>.
C numbered workers, each one only available at time t.

every worker can execute at most one task, find the maximum number of tasks that can be executed.

# solution
store chickens in a multiset.
order cows by s

for each cow, find a chicken with upper_bound(s). If the chicken is in [s,f], remove it from the multiset and add 1 to the counter. else do nothing.

## time complexity
ordering cows = NlogN
insert chickens in multiset = ClogC
upper bounds = NlogN
chickens removed = ClogC

total = O(NlogN + ClogC)


