# Problem
Given N points <x,y> connected by M edges to form 1+ graphs.
Find the smalles possible rectangular perimeter (parrallel to x and y axis) that contains at least one graph.

# Solution
- create a different set for each graph: dfs all nodes 
- dfs, save maximum x and y size for each graph.

1. insert nodes in an unordered set S
2. empty ordered set of graphs G, storing the maximum x and y extension of a graph. 
3. dfs for every node s in S
    1. create a new Graph item g with g.x = 0 and g.y = 0
    2. for every node visited by dfs:
        1. when dfs visits a node v, remove it from S if it is still present.
        2. if |v.x - g.x| > g.x then g.x = v.x
        3. if |v.y - g.y| > g.y then g.y = v.y
4. take from G the node with lowest g.x and g.y . perimeter = g.x * 2 + g.y * 2

## complexity 
Insert/remove N nodes in unordered set -> O(N)
Insert G <= N graphs in ordered set -> O(NlogN)
DFS on G nodes -> O(NlogN)
minimum from ordered set -> O(logN)

total: NlogN

## improvements
binary array in place of set